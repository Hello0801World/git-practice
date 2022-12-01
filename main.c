#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PlaylistNode.h"

PlaylistNode* ExecuteMenu(char option, char playlistTitle[], PlaylistNode* headNode);

void PrintMenu(char playlistTitle[]) {
   char option;
   PlaylistNode* headNode = NULL;
   headNode = (PlaylistNode*)malloc(sizeof(PlaylistNode));
   
   printf("%s PLAYLIST MENU\n", playlistTitle);
   
   
      scanf("%c", &option);
   
   do{
      printf("a - Add song\n");
      printf("r - Remove song\n");
      printf("c - Change position of song\n");
      printf("s - Output songs by specific artist\n");
      printf("t - Output total time of playlist (in seconds)\n");
      printf("o - Output full playlist\n");
      printf("q - Quit\n\n");
      printf("Choose an option:\n");
      scanf("%c", &option);
      
      ExecuteMenu(option, playlistTitle, headNode);
      
   }while (option !='q');
   
}

PlaylistNode* ExecuteMenu(char option, char playlistTitle[], PlaylistNode* headNode) {
   PlaylistNode* currNode = (PlaylistNode*)malloc(sizeof(PlaylistNode));
   currNode = headNode;
   
   if(option == 'o'){
      
      
      int count = 1;
      printf("%s - OUTPUT FULL PLAYLIST\n", playlistTitle);
      
      while(headNode != NULL){
         
         printf("%d.\n", count);
         PrintPlaylistNode(currNode);
         currNode = GetNextPlaylistNode(currNode);
         count++;
      }
      
      if(headNode == NULL)
         printf("Playlist is empty\n");
   }
   
   currNode = headNode;
   
   if(option =='a'){
      char id [50];
      char name[50];
      char artist[50];
      int length;
      
      printf("ADD SONG");
      printf("Enter song's unique ID:\n");
      fgets(id, 50,stdin);
      id[strlen(id)-1]='\0';
      
      printf("Enter song's name:\n");
      fgets(name, 50,stdin);
      name[strlen(name)-1]='\0';
      
      printf("Enter artist's name:\n");
      fgets(artist, 50,stdin);
      artist[strlen(artist)-1]='\0';
      
      printf("Enter song's length (in seconds):\n");
      scanf("%d", &length);
      
      CreatePlaylistNode(headNode, id, name, artist, length, currNode);
   }
   
   currNode = headNode;
   if(option == 'r'){
      
   }
   
   currNode = headNode;
   if(option == 't'){
      int sum = currNode->songLength;
      currNode = GetNextPlaylistNode(currNode);
      
      while(currNode!=NULL){
         sum = sum + currNode->songLength;
         currNode = GetNextPlaylistNode(currNode);
      }
      
      printf("OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n");
      printf("Total time: %d", sum);
   }
   
   if(option == 's'){
      char specificArtist [50];
      printf("OUTPUT SONGS BY SPECIFIC ARTIST\n");
      printf("Enter artist's name:\n");
      fgets(specificArtist, 50, stdin);
      specificArtist[strlen(specificArtist)-1]='\0';
      
      if(headNode == NULL)
         printf("Playlist is empty\n");
      
      int count = 1;
      
      while(headNode != NULL){
         if(strcmp(specificArtist, currNode->artistName)==0){
            printf("%d.\n", count);
            PrintPlaylistNode(currNode);
            count++;
         }
         currNode = GetNextPlaylistNode(currNode);
      }
   }
   
   
   return headNode;
}

int main(void) {
   char PlaylistTitle [50];
   
   printf("Enter playlist's title:\n");
   fgets(PlaylistTitle, 50, stdin);
   PlaylistTitle[strlen(PlaylistTitle)-1] = '\0';
   printf("\n");
   PrintMenu(PlaylistTitle);
   
   
   
   
   
   
   
   return 0;
}