# 🐞 Weekly Bug Report

_Last updated: 2025-06-28_

## 📁 Static Analysis (cppcheck)

  if( pgsz<512 || pgsz>65536 || (pgsz&(pgsz-1))!=0 ) goto readHexDb_error;
sqlite-lib/shell.c:32833:7: error: Common realloc mistake: 'zSql' nulled but not freed upon failure [memleakOnRealloc]
sqlite-lib/shell.c:33355:9: error: Common realloc mistake: 'azCmd' nulled but not freed upon failure [memleakOnRealloc]
sqlite-lib/shell.c:22797:23: warning: Either the condition 'pArg' is redundant or there is possible null pointer dereference: p. [nullPointerRedundantCheck]
sqlite-lib/shell.c:23484:35: warning: Either the condition 'z==0' is redundant or there is possible null pointer dereference: z. [nullPointerRedundantCheck]
sqlite-lib/shell.c:23960:16: warning: Either the condition 'pArg' is redundant or there is possible null pointer dereference: p. [nullPointerRedundantCheck]
sqlite-lib/shell.c:23961:3: warning: Either the condition 'pArg' is redundant or there is possible null pointer dereference: p. [nullPointerRedundantCheck]
sqlite-lib/shell.c:23962:3: warning: Either the condition 'pArg' is redundant or there is possible null pointer dereference: p. [nullPointerRedundantCheck]
sqlite-lib/shell.c:23963:3: warning: Either the condition 'pArg' is redundant or there is possible null pointer dereference: p. [nullPointerRedundantCheck]
sqlite-lib/shell.c:24613:7: warning: Either the condition 'pArg' is redundant or there is possible null pointer dereference: pArg. [nullPointerRedundantCheck]
sqlite-lib/shell.c:32829:20: warning: Either the condition 'zLine' is redundant or there is possible null pointer dereference: zLine. [nullPointerRedundantCheck]
  const char *zErr;         /* Compile error message */
sqlite-lib/shell.c:16069:40: style: inconclusive: Function 'sqlite3_intck_error' argument 1 names different: declaration 'pCk' definition 'p'. [funcArgNamesDifferent]
int sqlite3_intck_error(sqlite3_intck *p, const char **pzErr){
sqlite-lib/shell.c:15147:40: note: Function 'sqlite3_intck_error' argument 1 names different: declaration 'pCk' definition 'p'.
int sqlite3_intck_error(sqlite3_intck *pCk, const char **pzErr);
sqlite-lib/shell.c:16069:40: note: Function 'sqlite3_intck_error' argument 1 names different: declaration 'pCk' definition 'p'.
int sqlite3_intck_error(sqlite3_intck *p, const char **pzErr){
sqlite-lib/shell.c:15328:14: error: va_list 'ap' was opened but not closed by va_end(). [va_end_missing]
sqlite-lib/sqlite3.c:109545:11: warning: Assert statement calls a function which may have desired side effects: 'sqlite3ExprIsInteger'. [assertWithSideEffect]
sqlite-lib/sqlite3.c:113152:15: warning: Assert statement calls a function which may have desired side effects: 'sqlite3GetInt32'. [assertWithSideEffect]
sqlite-lib/sqlite3.c:131454:22: warning: Assert statement calls a function which may have desired side effects: 'sqlite3_value_blob'. [assertWithSideEffect]
sqlite-lib/sqlite3.c:131685:18: warning: Assert statement calls a function which may have desired side effects: 'sqlite3_value_blob'. [assertWithSideEffect]
sqlite-lib/sqlite3.c:186889:38: warning: Assert statement modifies 'x'. [assignmentInAssert]
sqlite-lib/sqlite3.c:144397:3: error: Address of local auto-variable assigned to a function parameter. [autoVariables]
sqlite-lib/sqlite3.c:146072:7: error: Address of local auto-variable assigned to a function parameter. [autoVariables]
sqlite-lib/sqlite3.c:153790:3: error: Address of local auto-variable assigned to a function parameter. [autoVariables]
sqlite-lib/sqlite3.c:36455:17: error: The address of local variable 'z' is accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:36456:12: error: The address of local variable 'z' is accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:36918:9: error: The address of local variable 'z' is accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:36920:30: error: The address of local variable 'z' is accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:36923:9: error: The address of local variable 'z' is accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:85561:17: warning: The address of local variable 'zToken' might be accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:115256:16: warning: The address of local variable 'zToken' might be accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:134251:16: warning: The address of local variable 'iCol' might be accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:134252:14: warning: The address of local variable 'iCol' might be accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:212857:14: warning: The address of local variable 'aBlob' might be accessed at non-zero index. [objectIndex]
sqlite-lib/sqlite3.c:27350:3: error: Common realloc mistake: 'p' nulled but not freed upon failure [memleakOnRealloc]
sqlite-lib/sqlite3.c:123766:9: warning: Either the condition 'db==0' is redundant or there is possible null pointer dereference: db. [nullPointerRedundantCheck]
sqlite-lib/sqlite3.c:144549:4: warning: Either the condition 'ppStmt==0' is redundant or there is possible null pointer dereference: ppStmt. [nullPointerRedundantCheck]
sqlite-lib/sqlite3.c:144698:4: warning: Either the condition 'ppStmt==0' is redundant or there is possible null pointer dereference: ppStmt. [nullPointerRedundantCheck]
sqlite-lib/sqlite3.c:147071:11: warning: Either the condition 'pColExpr!=0' is redundant or there is possible null pointer dereference: pColExpr. [nullPointerRedundantCheck]
sqlite-lib/sqlite3.c:187387:10: warning: Either the condition 'zFilename' is redundant or there is possible null pointer dereference: zFilename. [nullPointerRedundantCheck]
sqlite-lib/sqlite3.c:187437:20: warning: Either the condition 'zFilename' is redundant or there is pointer arithmetic with NULL pointer. [nullPointerArithmeticRedundantCheck]
sqlite-lib/sqlite3.c:88459:11: warning: Redundant assignment of 'nByte' to itself. [selfAssignment]
  int nErr = 0;                   /* Number of errors encountered */
  char **pzErrMsg             /* Write error messages here */
  char **pzErrMsg             /* Write error messages here */
  char **pzErrMsg             /* Write error messages here */
  char **pzErrMsg             /* Write error messages here */
   Expr *pError         /* Associate error with this expression */
  Expr *pError           /* Associate the error with the expression */
sqlite-lib/sqlite3.c:125144:10: warning: Size of pointer 'zExtra' used instead of size of its data. [pointerSize]
sqlite-lib/sqlite3.c:138447:11: style: struct member 'sqlite3_api_routines::result_error' is never used. [unusedStructMember]
  void  (*result_error)(sqlite3_context*,const char*,int);
sqlite-lib/sqlite3.c:138448:11: style: struct member 'sqlite3_api_routines::result_error16' is never used. [unusedStructMember]
  void  (*result_error16)(sqlite3_context*,const void*,int);
sqlite-lib/sqlite3.c:138515:10: style: struct member 'sqlite3_api_routines::result_error_nomem' is never used. [unusedStructMember]
  void (*result_error_nomem)(sqlite3_context*);
sqlite-lib/sqlite3.c:138516:10: style: struct member 'sqlite3_api_routines::result_error_toobig' is never used. [unusedStructMember]
  void (*result_error_toobig)(sqlite3_context*);
sqlite-lib/sqlite3.c:138524:10: style: struct member 'sqlite3_api_routines::result_error_code' is never used. [unusedStructMember]
  void (*result_error_code)(sqlite3_context*,int);
sqlite-lib/sqlite3.c:138672:9: style: struct member 'sqlite3_api_routines::error_offset' is never used. [unusedStructMember]
  int (*error_offset)(sqlite3*);
sqlite-lib/sqlite3.c:129378:7: error: Null pointer dereference: (struct VTable*)0 [nullPointer]
sqlite-lib/sqlite3.c:42520:3: error: Uninitialized variable: rc [uninitvar]
sqlite-lib/shell.c:22797:23: warning: Null pointer dereference: p [ctunullpointer]
sqlite-lib/shell.c:23960:16: warning: Null pointer dereference: p [ctunullpointer]
sqlite-lib/shell.c:24613:7: warning: Null pointer dereference: pArg [ctunullpointer]
sqlite-lib/sqlite3.c:26762:8: error: Null pointer dereference: pVfs [ctunullpointer]
sqlite-lib/sqlite3.c:144549:4: warning: Null pointer dereference: ppStmt [ctunullpointer]
sqlite-lib/sqlite3.c:144698:4: warning: Null pointer dereference: ppStmt [ctunullpointer]
