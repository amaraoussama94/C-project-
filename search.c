///////////////////////////////////////////////
// derniere modification:16/03/2017         //
// fonction  recherchhe produit par  nom   //
////////////////////////////////////////////
//derniere mise  a jour 26/10/2022
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


