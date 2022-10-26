//////////////////////////////////////
// derniere modification:10/03/2017 //
// fonction menu                    //
/////////////////////////////////////
//Update of this file 26/10/2022


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
