#ifndef PLAYLISTNODE_H_
#define PLAYLISTNODE_H_

typedef struct PlaylistNode_struct{
   char unique[50];
   char songName[50];
   char artistName[50];
   int songLength;
   struct PlaylistNode_struct* nextNodePtr;
   }PlaylistNode;
   
   void CreatePlaylistNode(PlaylistNode* thisNode, char* unique, char* songName, char* artistName, int songLength, PlaylistNode* newNode);
   void InsertPlaylistNodeAfter(PlaylistNode* thisNode, PlaylistNode* newNode);
   void SetNextPlaylistNode(PlaylistNode* thisNode, PlaylistNode* newNode);
   PlaylistNode* GetNextPlaylistNode(PlaylistNode* thisNode);
   void PrintPlaylistNode(PlaylistNode * thisNode);
   
#endif