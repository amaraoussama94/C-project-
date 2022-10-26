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

			if(choixSS==1)	{   // entr�e num�ro du produit : lire une structure � partir du fichier
                Lecture1Structure( fichier, len ,TailleStructure ,PointeurProduit );
                system("cls");///clear screan
			 	AfficherProduit (ProduitEncoure );
		                     }
			else if(choixSS==2)// entr�e nom du produit : lire une structure � partir du fichier
					 		LectureDeTTStruct(fichier, len, TailleStructure,PointeurProduit,PointeurMemDeStruct);
		     else if(choixSS==3){// rchercher un produit par nom: lire une structure � partir du fichier
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
