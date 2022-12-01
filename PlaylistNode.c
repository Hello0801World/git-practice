#include <stdio.h>
#include <string.h>

#include "PlaylistNode.h"

   void CreatePlaylistNode(PlaylistNode* thisNode, char* unique, char* songName, char* artistName, int songLength, PlaylistNode* newNode){
      strcpy(thisNode->unique, unique);
      strcpy(thisNode->songName, songName);
      strcpy(thisNode->artistName, artistName);
      thisNode->songLength = songLength;
      thisNode->nextNodePtr =NULL;
      thisNode->nextNodePtr = newNode;
   }
   
   void InsertPlaylistNodeAfter(PlaylistNode* thisNode, PlaylistNode* newNode){
      PlaylistNode * tempNext = NULL;
      
      tempNext = thisNode->nextNodePtr;
      thisNode->nextNodePtr = newNode;
      newNode->nextNodePtr = tempNext;
   }
   
   void SetNextPlaylistNode(PlaylistNode* thisNode, PlaylistNode* newNode){
      thisNode->nextNodePtr = newNode;
   }
   
   PlaylistNode* GetNextPlaylistNode(PlaylistNode* thisNode){
      return thisNode->nextNodePtr;
   }
   void PrintPlaylistNode(PlaylistNode * thisNode){
      printf("Unique ID: %s\n", thisNode->unique);
      printf("Song Name: %s\n", thisNode->songName);
      printf("Artist Name: %s\n", thisNode->artistName);
      printf("Song Length (in seconds): %d\n", thisNode->songLength);
      printf("\n");
   }
   
   
   