 /////////////////////////////////////
// derniere modification:10/03/2017 //
// fonction Afficher produit        //
/////////////////////////////////////
//derniere  modification 26/10/2022
 
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