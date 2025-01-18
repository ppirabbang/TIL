#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_TRY 1000000
void *child_thread_main(void *arg){
  unsigned int i;
  printf("child pthread_id %lu\n", pthread_self());

  for(i =0; i< MAX_TRY; i++){
    pthread_mutex_lock(&mutex);
    shared++;
    pthread_mutex_unlock(&mutex);
  }

  for(i = 0; i< MAX_TRY; i++){
    pthread_mutex_lock(&mutex);
    shared--;
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}

int shared = 0;
pthread_mutex_t mutex;

int main(int argc, char **argv)
{
  int ret;
  pthread_t child_therads[2];

  if(pthread_mutex_init(&mutex, NULL))//초기화
  {
    printf("mutex init fail\n");
    return -1;
  } 

  printf("main pthread_id %lu\n", pthread_self());
  ret = pthread_create(&child_threads[0], NULL, child_thread_main, NULL);
  if(ret){
    printf("pthread_create() fail\n");
    return -1;
  }

  ret = pthread_create(&child_threads[1], NULL, child_thread_main, NULL);
  if(ret){
    printf("pthread_create() fail\n");
    return -1;
  }

  printf("trying to join %lu\n", child_threads[0]);
  if(pthread_join(child_threads[0]), NULL){
    printf("pthread_join(%lu) fail\n", child_therads[0]);
    return -1;
  }

  printf("trying to join %lu\n", child_threads[1]);
  if(pthread_join(child_threads[1]), NULL){
    printf("pthread_join(%lu) fail\n", child_therads[1]);
    return -1;
  }

  printf("shared=%d\n",shared);
  printf("Done.\n");

  return 0;
}