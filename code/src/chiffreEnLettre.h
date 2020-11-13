typedef struct _ChiffreLettre ChiffreLettre;

extern void *(*chiffreEnLettre_malloc)(size_t size);

extern void *(*chiffreEnLettre_realloc)(void *ptr, size_t size);

extern void (*chiffreEnLettre_free)(void *ptr);

extern unsigned int chiffreEnLettre_get_nombre(const ChiffreEnLettre *chiffreEnLettre);

extern char chiffreEnLettre_get_mot(const ChiffreEnLettre *chiffreEnLettre);

extern static struct ChiffreEnLettre *_fill(ChiffreEnLettre *chiffreEnLettre, const unsigned nombre, const char mot);

extern static ChiffreEnLettre *_create(const unsigned int nombre, const char mot);

extern void chiffreEnLettre_destroy(ChiffreEnLettre *chiffreEnLettre);
