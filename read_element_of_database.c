

//////////////////////////////////////////////
// derniere modification:10/03/2017         //
// fonction  Lecture du un seulStructure    //
/////////////////////////////////////////////

//dernierre mise  a joir 22/10/2022
  void Lecture1Structure(FILE *fichier, int len, int TailleStructure,struct prod *PointeurProduit )
{ 	int num;

	     printf("donner le nemero du produit a charger entre 1 et %d :",  (int)(len/TailleStructure ) );    //int pour focer donner un entier
             scanf("%d",&num);
             if(num<= (int)(len/TailleStructure ))
			   {
			    fseek(fichier,  (num-1)*TailleStructure ,SEEK_SET);
			 	fread(PointeurProduit,TailleStructure,1,fichier);
			   }
			 else  printf("le numero est faux");    //int pour focer donner un entier
}

/////////////////////////////////////////////
// derniere modification:10/03/2017         //
// fonction  Lecture de tt les Structure   //
/////////////////////////////////////////////
  void LectureDeTTStruct(FILE *fichier, int len, int TailleStructure,struct prod *PointeurProduit, struct  prod  *PointeurMemDeStruct )
{ int i;
	int NbreProuit=(int)(len/TailleStructure );
	printf("num est %d",NbreProuit);
    PointeurMemDeStruct=malloc(TailleStructure*NbreProuit);
	fseek(fichier, 0 ,SEEK_SET);
	fread(PointeurMemDeStruct,TailleStructure,NbreProuit,fichier);

	system("cls");
	for(i=0;i<NbreProuit;i++){
						  memcpy(PointeurProduit, (PointeurMemDeStruct+i), TailleStructure+1);//permet de copy le continu de pointeur produit dan pointerMem
						  AfficherProduit (*PointeurProduit );//si on met prduit encour rien ne fonctionne
						                                      //car tt simplement ici aucun lien entre pointeur produit
														      /// et produit en cour il sont 2 don�e diif
			               }

	free(PointeurMemDeStruct);
}