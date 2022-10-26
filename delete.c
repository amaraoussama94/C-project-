/////////////////////////////////////////////////////
// derniere modification:16/03/2017               //
// fonction  supprimer d un element du fichier   //
/////////////////////////////////////////////////
//derniere mise  a jour 26/10/2022
void supprimerElement(int TailleStructure,FILE *fichier,int numprod )
{ FILE *fichier1;//
  int i,valeur;

   printf("\n donner le numero d element a supprimer entre 1 et %d  :\n",numprod);
    scanf("%d",&valeur);
    fichier1=fopen("E:\\stocktempo.txt","ab");

          if(fichier1!=NULL)
          	{
			  fseek(fichier1, 0 ,SEEK_SET);


               // while((i!=valeur)&&(i<numprod)){
               	fwrite(fichier,TailleStructure,2,fichier1);
          	memcpy(fichier1, fichier, TailleStructure+1);

			//	}

            	 fclose(fichier);
            	 fclose(fichier1);
		  }
	  	else  {
	  		printf("probleme d ouverture de fichier");
		  getch();
		  } /*
remove("E:\\stock.txt");
	rename("E:\\stocktempo.txt","E:\\stock.txt");   //permet de renommer le fichier*/

}
//////////////////////////////////////////////
// derniere modification:10/03/2017         //
// fonction  supprimer le fichier          //
/////////////////////////////////////////////
 void SuppFich( )
{
 int ret;

   ret = remove("E:\\stock.txt"); //pour supprimer le fichier

   if(ret == 0)
   {
      printf("\n File deleted successfully");
      getch();
   }
   else
   {
      printf("\n Error: unable to delete the file");
      getch();
   }
}
