#pragma once
// 7-dfsbfs.h

#ifndef DFSBFS_H
#define DFSBFS_H

#define MAX 11  // 그래프의 노드 수
#define QUEUE_SIZE 100

// 함수 선언
void dfs(int start, int target);
void bfs(int start, int target);

#endif // DFSBFS_H
