#ifndef SHARED_SHARED_SCENEPRIMARYACTORS_H
#define SHARED_SHARED_SCENEPRIMARYACTORS_H


typedef struct Shared_ScenePrimaryActors Shared_ScenePrimaryActors;
struct Shared_ScenePrimaryActors {
    void * actors[4]; /* +0x0: src/func_80286A78.c */
    void * kindBd7; /* +0x10: src/func_80286A78.c */
};
typedef char Shared_ScenePrimaryActors_size_check[(sizeof(Shared_ScenePrimaryActors) == 0x14) ? 1 : -1];

#endif
