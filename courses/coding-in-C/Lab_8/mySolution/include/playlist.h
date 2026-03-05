#ifndef PLAYLIST_H
#define PLAYLIST_H


#define MAX_SONGS 10
#define CONST_ADD 1
#define CONST_DELETE_FIRST 2
#define CONST_DELETE_PLAYLIST 3
#define CONST_DELETE_TITLE 4
#define CONST_PRINT_PLAYLIST 5
#define CONST_COUNT_ELEMENT 6
#define CONST_EXIT 7

typedef struct Song
{
	char* song_title;
	char* artist_name;

	struct Song* next_Song_ptr;

} Song;

typedef struct Playlist
{

	Song* head_song;

	int count;

} Playlist;

Playlist init_playlist(void);
void add_song(Playlist* origin_playlist);
void delete_first_Song(Playlist* origin_playlist);
void delete_playlist(Playlist* origin_playlist);
void delete_song_by_title(Playlist* origin_playlist, const char* title);

char* get_string(const char* Input_Name);
void print_playlist(Playlist* origin_playlist);
int count_playlist_elements(Playlist* origin_playlist);

int menu(void);

void insert_at_position(Playlist* origin_playlist, int position);



#endif
