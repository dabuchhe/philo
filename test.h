typedef struct s_fork
{
    int             id;
    bool            is_used;
    pthread_mutex_t mtx;
}   t_fork;

typedef struct s_philo
{
    int             id;
    pthread_t       thread;
    t_fork          *l_fork;
    t_fork          *r_fork;
}   t_philo;

typedef struct  s_time
{
    unsigned int    die;
    unsigned int    eat;
    unsigned int    sleep;
    unsigned int    need;
}   t_time;

typedef struct s_data
{
    pthread_mutex_t mutex_print;
    pthread_mutex_t death;
    int             nb_philo;
    int             time_to_die;    //
    int             time_to_eat;    //
    int             time_to_sleep;  //
    int             must_eat;       //
    int             err;

    t_philo         *philo;
}   t_data;