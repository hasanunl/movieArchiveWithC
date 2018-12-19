#include <stdio.h>
#include<stdlib.h>
#include <memory.h>


struct movie{
    char movieName[50];
    int releaseDate;
    char director[50];
    char scriptWriter[50];
    char leadActor[50];
};

int main() {
    int structSize = 50;
    struct movie movies[structSize];
    int choice;
    int movieCount = 0;
    while(choice != 6){
        printf("1. Film ekle \n");
        printf("2. Filmleri listele \n");
        printf("3. Film güncelle \n");
        printf("4. Film sil \n");
        printf("5. Film ara \n");
        printf("6. Cikis \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Filmin adini giriniz :");
                scanf("%s",movies[movieCount].movieName);
                printf("Filmin gösterim yilini giriniz :");
                scanf("%d",&movies[movieCount].releaseDate);
                printf("Filmin yonetmenini giriniz :");
                scanf("%s",movies[movieCount].director);
                printf("Filmin senaristini giriniz :");
                scanf("%s",movies[movieCount].scriptWriter);
                printf("Filmin basrol oyuncusunu giriniz :");
                scanf("%s",movies[movieCount].leadActor);
                movieCount++;
                printf("Film basarili sekilde eklendi! \n");
                break;
            case 2:
                for(int i=0;i<movieCount;i++){
                    for(int j=0;j<movieCount;j++){
                        if(movies[i].releaseDate<=movies[j].releaseDate)
                        {
                            struct movie temp = movies[i];
                            movies[i] = movies[j];
                            movies[j] = temp;
                        }
                    }
                }
                for(int i=0;i<movieCount;i++){
                    printf("%s \n",movies[i].movieName);
                    printf("%d \n",movies[i].releaseDate);
                    printf("%s \n",movies[i].director);
                    printf("%s \n",movies[i].scriptWriter);
                    printf("%s \n",movies[i].leadActor);
                    printf("\n");
                }
                break;
            case 3:
                printf("Guncellenicek filmin adini girin : \n");
                char updateName[50];
                scanf("%s",updateName);
                for(int l=0;l<structSize;l++){
                    if(strcmp(movies[l].movieName,updateName) == 0){
                        printf("Filmin adini giriniz :");
                        scanf("%s",movies[l].movieName);
                        printf("Filmin gösterim yilini giriniz :");
                        scanf("%d",&movies[l].releaseDate);
                        printf("Filmin yonetmenini giriniz :");
                        scanf("%s",movies[l].director);
                        printf("Filmin senaristini giriniz :");
                        scanf("%s",movies[l].scriptWriter);
                        printf("Filmin basrol oyuncusunu giriniz :");
                        scanf("%s",movies[l].leadActor);
                        break;
                    }
                }
                break;
            case 4:
                printf("Silinicek filmin adini girin : \n");
                char deleteName[50];
                scanf("%s",deleteName);
                for(int i=0;i<structSize;i++){
                    printf("%s \n",movies[i].movieName);
                    if(strcmp(movies[i].movieName,deleteName) == 0){
                        printf("Film silinecektir! e/herhangi bir tus! \n");
                        char approve[50];
                        scanf("%s",approve);
                        if(strcmp(approve,"e") == 0){
                            for(int j=i;j<structSize-1;j++){
                                movies[j]=movies[j+1];
                            }
                            movieCount--;
                            break;
                        }
                        break;
                    }
                }
                break;
            case 5:
                printf("Film aramak için kategori secin : \n");
                printf("Film adina göre arama için 1 : \n");
                printf("Film yılına göre arama için 2 : \n");
                printf("Filmin yönetmenine göre arama için 3 : \n");
                printf("Film yazarına göre arama için 4 : \n");
                printf("Filmin basrol oyuncusuna göre arama için 5 : \n");
                int searchChoice;
                scanf("%d",&searchChoice);
                switch(searchChoice)
                {
                    case 1:
                        printf("Filmin adini giriniz : \n");
                        char searchMovieName[50];
                        scanf("%s",searchMovieName);
                        for(int i=0;i<structSize;i++){
                            if(strcmp(movies[i].movieName,searchMovieName) == 0){
                                printf("%s \n",movies[i].movieName);
                                printf("%d \n",movies[i].releaseDate);
                                printf("%s \n",movies[i].director);
                                printf("%s \n",movies[i].scriptWriter);
                                printf("%s \n",movies[i].leadActor);
                                printf("\n");
                            }
                        }
                        break;
                    case 2:
                        printf("Filmin yılını giriniz : \n");
                        int searchMovieDate;
                        scanf("%d",&searchMovieDate);
                        for(int i=0;i<structSize;i++){
                            if(movies[i].releaseDate == searchMovieDate){
                                printf("%s \n",movies[i].movieName);
                                printf("%d \n",movies[i].releaseDate);
                                printf("%s \n",movies[i].director);
                                printf("%s \n",movies[i].scriptWriter);
                                printf("%s \n",movies[i].leadActor);
                                printf("\n");
                            }
                        }
                        break;
                    case 3:
                        printf("Filmin yönetmemini giriniz : \n");
                        char searchMovieDirector[50];
                        scanf("%s",searchMovieDirector);
                        for(int i=0;i<structSize;i++){
                            if(strcmp(movies[i].director,searchMovieDirector) == 0){
                                printf("%s \n",movies[i].movieName);
                                printf("%d \n",movies[i].releaseDate);
                                printf("%s \n",movies[i].director);
                                printf("%s \n",movies[i].scriptWriter);
                                printf("%s \n",movies[i].leadActor);
                                printf("\n");
                            }
                        }
                        break;
                    case 4:
                        printf("Filmin yazarini giriniz : \n");
                        char searchMovieWriter[50];
                        scanf("%s",searchMovieWriter);
                        for(int i=0;i<structSize;i++){
                            if(strcmp(movies[i].scriptWriter,searchMovieWriter) == 0){
                                printf("%s \n",movies[i].movieName);
                                printf("%d \n",movies[i].releaseDate);
                                printf("%s \n",movies[i].director);
                                printf("%s \n",movies[i].scriptWriter);
                                printf("%s \n",movies[i].leadActor);
                                printf("\n");
                            }
                        }
                        break;
                    case 5:
                        printf("Filmin basrol oyunucusu giriniz : \n");
                        char searchMovieActor[50];
                        scanf("%s",searchMovieActor);
                        for(int i=0;i<structSize;i++){
                            if(strcmp(movies[i].leadActor,searchMovieActor) == 0){
                                printf("%s \n",movies[i].movieName);
                                printf("%d \n",movies[i].releaseDate);
                                printf("%s \n",movies[i].director);
                                printf("%s \n",movies[i].scriptWriter);
                                printf("%s \n",movies[i].leadActor);
                                printf("\n");
                            }
                        }
                        break;
                    default:
                        printf("Gecerli bir secim yapiniz!\n");
                }
                break;
            case 6:
                printf("exit");
                break;
            default:
                printf("Input a valid input \n");
        }
    }
    return 0;
}

