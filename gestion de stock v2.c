#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct prod
{
	char Nom_de_produit[80];
	int Nombre_Stock;
	float Prix_Achat ;
	float Prix_Vente;
	int Num_Prod ;
 } ;


//////////////////////////////////////
// derniere modification:10/03/2017 //
// fonction menu                    //
/////////////////////////////////////

 int prod ()
{ int choix ;

system("cls");///clear screan
     printf("\n -------------------------------------------------------------------- ");
     printf("\n -- taper --> 1 pour l'ajout d'un produit                          --");
     printf("\n -- taper --> 2 pour afficher le produit en cours                  --");
     printf("\n -- taper --> 3 Lecture d'un produit a partir du fichier           --");
     printf("\n -- taper --> 4 pour modifier                                      --");
     printf("\n -- taper --> 5 pour  supprimer le fichier                         --");
	 printf("\n -- taper --> 0 pour quitter l'application'                        --\n");
     printf("\n -------------------------------------------------------------------- \n");
     scanf("%d",&choix);
getch();

	return(choix);
 }

//////////////////////////////////////
// derniere modification:10/03/2017 //
// fonction itroduction du produit  //
/////////////////////////////////////


 void IntroduireProduit (struct prod *k )
{
char chaine[80];


system("cls");///clear screan
     gets(chaine);
     printf("\n donner le nom de produit : ");
     gets(k->Nom_de_produit);
    // gets(chaine);
     printf("\n donner le nombre stock  : ");
     scanf("%d",&k->Nombre_Stock);
    // gets(chaine);
     printf("\n donner le prix d achat  :");
     scanf("%f",&k->Prix_Achat);
    // gets(chaine);
     printf("\n donner le Prix de vente  :");
     scanf("%f",&k->Prix_Vente);
    // gets(chaine);
     printf("\n donner Numero de produit  : ");
     scanf("%d",&k->Num_Prod);
 }



//////////////////////////////////////
// derniere modification:10/03/2017 //
// fonction Afficher produit        //
/////////////////////////////////////


 void AfficherProduit (struct prod k )
{

     printf("\n  le nom de produit :%s ",k.Nom_de_produit);
     printf("\n  Nombre_Stock :%d ",k.Nombre_Stock);
     printf("\n  Prix_Achat :%.3f ",k.Prix_Achat);
     printf("\n  Prix_Vente :%.3f ",k.Prix_Vente);
     printf("\n  Num_Prod %d :",k.Num_Prod);

// getch();
 getch();

 }
 //////////////////////////////////////////////////////////////
// derniere modification:10/03/2017                         //
// fonction rechercher apartir du fichier pour afficher .. //
////////////////////////////////////////////////////////////
 int   MenuSup()
{ int choixSup ;

system("cls");///clear screan
     printf("\n -------------------------------------------------------------------- ");
     printf("\n -- taper --> 1 pour supprimer le fichier                          -- ");
     printf("\n -- taper --> 2 pour supprimer un produit                          -- \n");
     printf("\n -------------------------------------------------------------------- \n");
     scanf("%d",&choixSup);
getch();

	return(choixSup);
 }
 //////////////////////////////////////////////////////////////
// derniere modification:10/03/2017                         //
// fonction rechercher apartir du fichier pour afficher .. //
////////////////////////////////////////////////////////////
 int   SSMenuLectureFichier()
{ int choixSS ;

system("cls");///clear screan
     printf("\n -------------------------------------------------------------------- ");
     printf("\n -- taper --> 1 pour afficher produit par numero                   -- ");
     printf("\n -- taper --> 2 pour recherche toouts les  produits                -- \n");
     printf("\n -- taper --> 3 pour recherche un produit par son nom              -- \n");
     printf("\n -------------------------------------------------------------------- \n");
     scanf("%d",&choixSS);
getch();

	return(choixSS);
 }
//////////////////////////////////////
// derniere modification:10/03/2017 //
// fonction Menu Modifier          //
/////////////////////////////////////


  int MenuModifier ()
{ int l ;

     system("cls");///clear screan
     printf("\n --------------------------------------------------------------------");
     printf("\n -- taper --> 1 pour modifier le nom du prooduit                   --");
     printf("\n -- taper --> 2 pour modifier le nombre stock                      --");
     printf("\n -- taper --> 3 pour modifier le prix d achat du prooduit          --");
     printf("\n -- taper --> 4 pour modifier le prix du vente du prooduit         --");
     printf("\n -- taper --> 5 pour modifier numero du prooduit                   --");
     printf("\n -------------------------------------------------------------------- \n");
     scanf("%d",&l);
     return(l);
 }

 //////////////////////////////////////
// derniere modification:10/03/2017  //
// fonction  Modifier               //
/////////////////////////////////////

 void Modifier (struct prod *k,int l )
 {char chaine[100];
     switch(l)
     {
     	case 1:
     	     gets(chaine);
		    printf("\n donner le nouveau nom de produit : ");
            gets(k->Nom_de_produit);
			break;
     	case 2:
		    printf("\n donner le nouveau nombre de stock: ");
           scanf("%d",&k->Nombre_Stock);
	        break;
     	case 3:
		    printf("\n donner le nouveau Prix Achat:" );
            scanf("%f",&k->Prix_Achat);
	        break;
     	case 4:
		    printf("\n donner le nouveau Prix Vente:");
            scanf("%f",&k->Prix_Vente);
	        break;
     	case 5:
		    printf("\n donner le nouveau Numero de Produit:");
            scanf("%d",&k->Num_Prod);
			break;
     	default: printf(" \n le choix est incorrecte:");

	 }
	 getch();
	 getch();
 }

//////////////////////////////////////////////
// derniere modification:10/03/2017         //
// fonction  Lecture du un seulStructure    //
/////////////////////////////////////////////
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
//////////////////////////////////////////////
// derniere modification:16/03/2017         //
// fonction  modification d'un element     //
/////////////////////////////////////////////
  void ModEle(FILE *fichier, int len,int l, int TailleStructure,struct prod *PointeurProduit )
{ 	int nummod;
     int NbreProuit=(int)(len/TailleStructure );
       	system("cls");
            printf("donnerl numero de produit a modifier enter 1 et %d :", NbreProuit);
		    scanf("%d",&nummod);

             if(nummod<= NbreProuit)
			   {
			     l=MenuModifier ();
			    fseek(fichier,  (nummod-1)*TailleStructure,SEEK_SET);
			 	 Modifier ( PointeurProduit,l );
		         fwrite(PointeurProduit,TailleStructure,1,fichier);
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
														      /// et produit en cour il sont 2 donée diif
			               }

	free(PointeurMemDeStruct);
}
///////////////////////////////////////////////
// derniere modification:16/03/2017         //
// fonction  recherchhe produit par  nom   //
////////////////////////////////////////////

void  RechPNom(FILE *fichier, int TailleStructure,struct prod *PointeurProduit)
{char nom[80];
  int trouve = 1;

  printf("Donnez le nom : ");
  scanf("%s",nom);
  fseek(fichier, 0, SEEK_SET);
  while (fread(PointeurProduit, TailleStructure, 1, fichier) != 0 && trouve != 0)
      {
       if ((trouve = strcmp(PointeurProduit->Nom_de_produit,nom)) == 0)

 printf("le nom de produit :%s \n Nombre de stock:%d \n Prix d achat :%f \n Prix de vente:%f \n Numero de produit:%d ",PointeurProduit->Nom_de_produit,PointeurProduit->Nombre_Stock,PointeurProduit->Prix_Achat,PointeurProduit->Prix_Vente,PointeurProduit->Num_Prod);
       getch();
      }
  if (trouve != 0) {
    printf("Ce nom n'existe pas\n");
    getch();
  }
}
/////////////////////////////////////////////////////
// derniere modification:16/03/2017               //
// fonction  supprimer d un element du fichier   //
//////////////////////////////////////////////////
void supprimerElement(int TailleStructure,FILE *fichier,int numprod )
{ FILE *fichier1;
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
//////////////////////////////////////
// derniere modification:10/03/2017 //
// fonction pricipale               //
/////////////////////////////////////

main()
{
FILE *fichier;

struct prod ProduitEncoure, *PointeurProduit, *PointeurMemDeStruct ;
PointeurProduit=&ProduitEncoure;
 int i,len,p,l,num,nummod,choixSup,TailleStructure,choixSS,numprod, choix;
 TailleStructure=(int)(sizeof(ProduitEncoure));
 fichier=fopen("D:\\stock.txt","ab");  // fichier de nom stock dans c de type binaire au mode a:
         if(fichier!=NULL){
         	fseek(fichier, 0, SEEK_END);
		    	len= ftell(fichier);
		    	numprod=(int)(len/TailleStructure );
		    	fclose(fichier);
		 }

    while((choix=prod())!=0)
	 {
	 	switch(choix)

	{
		case 1:

         fichier=fopen("D:\\stock.txt","ab");  // fichier de nom stock dans c de type binaire au mode a:
         if(fichier!=NULL)
           {printf("donner le nombre de produit a introduire");
           scanf("%d",&p);
           for(i=0;i<p;i++)
           	  {
           	IntroduireProduit ( PointeurProduit) ;
             fwrite(PointeurProduit,TailleStructure,1,fichier);
			   }

          fclose(fichier);
		  }
	  	else  {
	  		printf("probleme d ouverture de fichier");
		  getch();
		  }
		break;
		case 2 :
		  	system("cls");///clear screan
			AfficherProduit (ProduitEncoure );
		  break;


		  case 3 :

		  choixSS=SSMenuLectureFichier();
		  fichier=fopen("D:\\stock.txt","rb");  // fichier de nom stock dans c de type binaire au mode a:
          if(fichier!=NULL)
           {
				fseek(fichier, 0, SEEK_END);
		    	len = ftell(fichier);

			if(choixSS==1)	{   // entrée numéro du produit : lire une structure à partir du fichier
                Lecture1Structure( fichier, len ,TailleStructure ,PointeurProduit );
                system("cls");///clear screan
			 	AfficherProduit (ProduitEncoure );
		                     }
			else if(choixSS==2)// entrée nom du produit : lire une structure à partir du fichier
					 		LectureDeTTStruct(fichier, len, TailleStructure,PointeurProduit,PointeurMemDeStruct);
		     else if(choixSS==3){// rchercher un produit par nom: lire une structure à partir du fichier
					 	     RechPNom(fichier,TailleStructure,PointeurProduit) ;

             fclose(fichier);}
             else printf("faux choix ");
             fclose(fichier);
		   }
		    else {
	  		printf("probleme d ouverture de fichier");
		  getch();
		  }
		  break;
	 	case 4 :

		 fichier=fopen("D:\\stock.txt","rb+");
		  if(fichier!=NULL)
           {  	fseek(fichier, 0, SEEK_END);
		    	len = ftell(fichier);

	             ModEle(fichier, len,l,TailleStructure,PointeurProduit );
                 fclose(fichier);
		    }
			else {
	  		printf("probleme d ouverture de fichier");

		  getch();
		  getch();
		  }
	 	break;
	 	case 5 :

	 		system("cls");///clear screan
	 		choixSup=MenuSup();

	 		 if(choixSup==1)
		     SuppFich( );

		     else if(choixSup==2)
		     	{		 fichier=fopen("D:\\stock.txt","rb+");
		  if(fichier!=NULL)
           {  supprimerElement(TailleStructure,fichier,numprod);

				     fclose(fichier);
		    }
			else {
	  		printf("probleme d ouverture de fichier");
		   }


		}


		     else printf("faux chois");

	 	break;
		default :  {
	  		printf("faux choix ");
		  getch();
		  }
	}
    }

}
