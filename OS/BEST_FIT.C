
#include<stdio.h>
int n_proc=4,n_mem=6,mem_loc[100],visited[100],mem_index=0,i,j,k;
    int mem_sizes[] = {200, 400, 600, 500, 300, 250};
    int process_sizes[] = {357, 210, 468, 491};

void initialize()
{
 for(i=0;i<n_mem;i++)
 {
   visited[i]=0;
   mem_loc[i]=-1;
 }
}

void bestfit()
{
    initialize();

    for (i = 0; i < n_proc; i++)
    {
        int min_diff = 9999;
        int best_fit_index = -1;

        for (j = 0; j < n_mem; j++)
        {
            int diff = mem_sizes[j] - process_sizes[i];

            if (diff >= 0 && diff < min_diff && visited[j] == 0)
            {
                min_diff = diff;
                best_fit_index = j;
            }
        }

        if (best_fit_index != -1)
        {
            visited[best_fit_index] = 1;
            mem_loc[i] = mem_sizes[best_fit_index];
        }
    }

    for (i = 0; i < n_proc; i++)
    {
        int hole = 0;
        if (mem_loc[i] != -1)
        {
            hole = mem_loc[i] - process_sizes[i];
            printf("\nProcess size = %d goes into memory = %d, and the hole is %d", process_sizes[i], mem_loc[i], hole);
        }
        else
        {
            printf("\nProcess size = %d could not be loaded", process_sizes[i]);
        }
    }
}
void next_fit()
{
   
    initialize();

    for (i = 0; i < n_proc; i++)
    {
        int min_diff = 9999;
        int best_fit_index = -1;
        int last_allocated_ind =-1;

        for (j = last_allocated_ind+1; j < n_mem; j++)
        {
            int diff = mem_sizes[j] - process_sizes[i];

            if (diff >= 0 && diff < min_diff && visited[j] == 0)
            {
                min_diff = diff;
                best_fit_index = j;
            }
        }

        if(best_fit_index != -1)
        {
            for (j = 0; j < last_allocated_ind; j++)
        {
            int diff = mem_sizes[j] - process_sizes[i];

            if (diff >= 0 && diff < min_diff && visited[j] == 0)
            {
                min_diff = diff;
                best_fit_index = j;
            }
        }

        }

        if (best_fit_index != -1)
        {
            visited[best_fit_index] = 1;
            mem_loc[i] = mem_sizes[best_fit_index];
        }
    }

    for (i = 0; i < n_proc; i++)
    {
        int hole = 0;
        if (mem_loc[i] != -1)
        {
            hole = mem_loc[i] - process_sizes[i];
            printf("\nProcess size = %d goes into memory = %d, and the hole is %d", process_sizes[i], mem_loc[i], hole);
        }
        else
        {
            printf("\nProcess size = %d could not be loaded", process_sizes[i]);
        }
    }
}
void first_fit()
{
    initialize();
    for(i=0;i<n_proc;i++)
    {
        for(j=0;j<n_mem;j++)
        {
            int diff = mem_sizes[j] - process_sizes[i];
            if(diff>=0 && visited[j]==0)
            {
                visited[j]=1;
                mem_loc[i]=mem_sizes[j];
                break;
            }
        }
    }
     for (i = 0; i < n_proc; i++)
    {
        int hole = 0;
        if (mem_loc[i] != -1)
        {
            hole = mem_loc[i] - process_sizes[i];
            printf("\nProcess size = %d goes into memory = %d, and the hole is %d", process_sizes[i], mem_loc[i], hole);
        }
        else
        {
            printf("\nProcess size = %d could not be loaded", process_sizes[i]);
        }
    }
}
void worstfit()
{
    initialize();

    for (i = 0; i < n_proc; i++)
    {
        int max_diff = -9999;
        int worst_fit_index = -1;

        for (j = 0; j < n_mem; j++)
        {
            int diff = mem_sizes[j] - process_sizes[i];

            if (diff >= 0 && diff > max_diff && visited[j] == 0)
            {
                max_diff = diff;
                worst_fit_index = j;
            }
        }

        if (worst_fit_index != -1)
        {
            visited[worst_fit_index] = 1;
            mem_loc[i] = mem_sizes[worst_fit_index];
        }
    }

    for (i = 0; i < n_proc; i++)
    {
        int hole = 0;
        if (mem_loc[i] != -1)
        {
            hole = mem_loc[i] - process_sizes[i];
            printf("\nProcess size = %d goes into memory = %d, and the hole is %d", process_sizes[i], mem_loc[i], hole);
        }
        else
        {
            printf("\nProcess size = %d could not be loaded", process_sizes[i]);
        }
    }
}

int main()
{ 
    printf("\nfirstfit\n");
    first_fit();
    printf("\n\nworstfit\n");
    worstfit();
return 0;

}