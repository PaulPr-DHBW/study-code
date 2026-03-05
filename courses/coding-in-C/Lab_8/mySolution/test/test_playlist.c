#include "../include/playlist.h"

#include <stdlib.h>
#include <assert.h>

void test_init_playlist();
void test_add_song();
void test_delete_first_song();
void test_delete_first_song_empty();
void test_delete_playlist();
void test_max_songs_limit();


int main()
{
    test_init_playlist();
    test_add_song();
    test_delete_playlist();


    test_delete_first_song();
    test_delete_first_song_empty();
    test_delete_playlist();
    test_max_songs_limit();


    printf("\nAssertion complete, no Errors found, Test Succesful!!");

    return 0;
}

void test_init_playlist()
{
    Playlist test = init_playlist();

    assert(test.count == 0);
    assert(test.head_song == NULL);
}

void test_add_song()
{
    Playlist test = init_playlist();

    add_song(&test);

    assert(test.count == 1);
    assert(test.head_song != NULL);
    assert(test.head_song->artist_name != NULL);
    assert(test.head_song->song_title != NULL);
    assert(test.head_song->next_Song_ptr == NULL);
}

void test_delete_playlist()
{
    Playlist test = init_playlist();

    for(int i = 0; i < 3; i++)
    {
        add_song(&test);
    }

    delete_playlist(&test);
    assert(test.count == 0);
    assert(test.head_song == NULL);
}

void test_delete_first_song()
{
    Playlist test = init_playlist();

    for(int i = 0; i < 3; i++)
    {
        add_song(&test);
    }

    Song *p_test_second_song = test.head_song->next_Song_ptr;

    delete_first_Song(&test);
    assert(p_test_second_song == test.head_song);
}

void test_delete_first_song_empty()
{
    Playlist test = init_playlist();
    delete_first_Song(&test);

    assert(test.head_song == NULL);
}

void test_max_songs_limit()
{
    Playlist test = init_playlist();

    for(int i = 0; i < MAX_SONGS+1; i++)
    {
        add_song(&test);
    }

    assert(count_playlist_elements(&test <= MAX_SONGS));
}