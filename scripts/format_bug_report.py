# This script processes a Cppcheck XML report and generates a Markdown formatted bug report.
# Usage: python format_bug_report.py <path_to_cppcheck_xml>
## Requirements:
# - Python 3.x
#Version: 1.0.0
#date: 2025-06-29

import sys
import xml.etree.ElementTree as ET
from collections import defaultdict
from datetime import date

def parse_cppcheck(xml_path):
    """
    Parses a Cppcheck XML report and extracts issues grouped by severity.
    Args:
        xml_path (str): The file path to the Cppcheck XML report.
    Returns:
        defaultdict: A dictionary where keys are severity levels (e.g., 'error', 'warning')
                     and values are lists of formatted issue strings describing the file,
                     line, message, and verbose description for each issue.
    """
    tree = ET.parse(xml_path)
    root = tree.getroot()

    issues = defaultdict(list)
    for error in root.findall("errors/error"):
        severity = error.attrib.get("severity", "unknown")
        msg = error.attrib.get("msg", "")
        verbose = error.attrib.get("verbose", "")
        for location in error.findall("location"):
            file = location.attrib.get("file", "")
            line = location.attrib.get("line", "")
            issues[severity].append(f"- `{file}:{line}`: {msg} ({verbose})")
    return issues

def generate_markdown(issues):
    """
    Generates a markdown-formatted weekly bug report from a dictionary of issues.
    Args:
        issues (dict): A dictionary where keys are issue types (e.g., 'error', 'warning')
            and values are lists of issue descriptions.
    Returns:
        str: A string containing the formatted markdown report, including a summary table
            and detailed sections for each issue type.
    """
    today = date.today().isoformat()
    md = [f"# 🐞 Weekly Bug Report\n\n📅 _Last updated: {today}_\n"]

    summary = {k: len(v) for k, v in issues.items()}
    md.append("## 📊 Summary\n")
    md.append("| Type | Count |")
    md.append("|------|-------|")
    for k in ["error", "warning", "style", "performance", "portability", "information"]:
        if k in summary:
            md.append(f"| {k.capitalize()} | {summary[k]} |")
    md.append("")

    for severity, entries in issues.items():
        md.append(f"## {severity.capitalize()}s\n")
        md.extend(entries)
        md.append("")

    return "\n".join(md)

if __name__ == "__main__":
    xml_path = sys.argv[1]
    issues = parse_cppcheck(xml_path)
    print(generate_markdown(issues))
