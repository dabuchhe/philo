// Prototype : int usleep(useconds_t usec);

// Entrée :
// usec : durée à dormir en microsecondes (useconds_t), doit être strictement inférieur à 1 000 000 (< 1 000 000).

// Sortie / Valeurs de retour :
// Retourne 0 en cas de succès.
// Retourne ‑1 en cas d’erreur (et errno est défini).

// Comportement :
// Suspend l’exécution du thread appelant pendant au moins usec microsecondes. Le délai peut être légèrement plus long selon le système.



// Prototype : int gettimeofday(struct timeval *tv, struct timezone *tz);

// Entrée :
// tv : pointeur vers une structure timeval (seconds + microseconds).
// tz : généralement NULL, contrôlait la timezone (désuet).

// Sortie / Valeurs de retour :
// Remplit tv (et tz si non NULL) ; retourne 0 en succès, ‑1 en erreur (errno défini).

// Usage : obtenir l’heure actuelle en secondes + microsecondes pour timestamping.



// Prototype : int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);

// Entrée :
// thread : sortie — identifiant du thread créé (pthread_t).
// attr : attributs du thread (peut être NULL pour défaut).
// start_routine : fonction à exécuter.
// arg : argument transmis à start_routine.

// Sortie / Valeurs de retour :
// Retourne 0 si succès, sinon un code d’erreur (non errno).

// Fonction : crée un nouveau thread qui exécutera start_routine(arg).



// Prototype : int pthread_detach(pthread_t thread);

// Entrée : 
// thread : identifiant du thread à détacher.

// Sortie / Valeurs de retour :
// Retourne 0 en succès, sinon un code d’erreur.

// Fonction : détache le thread pour que ses ressources soient automatiquement libérées à sa terminaison (on ne peut plus join ce thread).



// Prototype : int pthread_join(pthread_t thread, void **retval);

// Entrée :
// thread : identifiant du thread à attendre.
// retval : pointeur pour récupérer la valeur retournée par le thread (pthread_exit).

// Sortie / Valeurs de retour :
// Retourne 0 en succès, sinon un code d’erreur.

// Fonction : suspend le thread appelant jusqu’à ce que thread se termine. Si retval non-NULL, récupère la valeur de retour du thread.

// 6 à 9. Opérations sur les mutex (pthread_mutex_*)
// Toutes ces fonctions sont décrites dans le manuel Linux/POSIX.
// Man7
// Linux Die

// pthread_mutex_init

// Prototype : int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

// Entrée :

// mutex : pointeur vers l’objet mutex.

// attr : attributs du mutex (NULL = défaut).

// Sortie / Valeurs de retour :

// Retourne 0 si succès, sinon un code d’erreur.

// Fonction : initialise un mutex inutilisé pour qu’il soit ensuite utilisable.
// Linux Die

// pthread_mutex_destroy

// Prototype : int pthread_mutex_destroy(pthread_mutex_t *mutex);

// Entrée : mutex : pointeur vers le mutex à détruire.

// Sortie / Valeurs de retour :

// Retourne 0 si succès, sinon un code d’erreur.

// Fonction : détruit un mutex précédemment initialisé et non verrouillé.
// Linux Die

// pthread_mutex_lock

// Prototype : int pthread_mutex_lock(pthread_mutex_t *mutex);

// Entrée : mutex : mutex à verrouiller.

// Sortie / Valeurs de retour :

// Retourne 0 si verrouillage réussi, sinon un code d’erreur (EINVAL, EDEADLK, etc.)
// Man7
// +1

// Fonction : verrouille le mutex. Si déjà verrouillé, le thread bloque jusqu’à ce qu’il soit libéré.
// Man7
// +1

// pthread_mutex_unlock

// Prototype : int pthread_mutex_unlock(pthread_mutex_t *mutex);

// Entrée : mutex : mutex à déverrouiller.

// Sortie / Valeurs de retour :

// Retourne 0 si succès, sinon un code d’erreur (EINVAL, EPERM, etc.)
// Man7
// +1

// Fonction : déverrouille le mutex. Comporte des comportements spécifiques selon le type de mutex (rapide, récursif, error-check).
// Man7
// +1