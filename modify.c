//////////////////////////////////////
// derniere modification:10/03/2017  //
// fonction  Modifier               //
/////////////////////////////////////
//vderniere mise  a jour 22/10/2022
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