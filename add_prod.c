//////////////////////////////////////
// derniere modification:10/03/2017 //
// fonction itroduction du produit  //
/////////////////////////////////////
//deriere mise a ajour 22/10/2022

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
