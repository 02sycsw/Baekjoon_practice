#include <stdio.h>
#include <stdlib.h>

int** create_Adj(int N, int M) {
    int** arr = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(N * sizeof(int));
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        arr[a - 1][b - 1] = 1;
        arr[b - 1][a - 1] = 1;
    }

    return arr;
}

void Dfs(int** arr, int v, int visted[], int N) {
    visted[v] = 1;
    printf("%3d -> ", v);
    for (int i = 0; i < N; i++) {
        if (arr[v][i] && !visted[i]) {
            Dfs(arr, i, visted, N);
        }
    }
}

void print_Adj(int** arr, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

void del_Adj(int** arr, int N) {
    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int** arr;
    int t_case;

    scanf("%d", &t_case);

    for (int i = 0; i < t_case; i++) {
        int N, M, count = 0;

        scanf("%d %d", &N, &M);
        arr = create_Adj(N, M);

        int* visited = (int*)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++) {
            arr[i] = 0;
        }

        Dfs(arr, 0, visited, N);
        printf("%d\n", count);
        print_Adj(arr, N);
        del_Adj(arr, N);
    }

    return 0;
}
