#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	if (s1 == NULL && s2 == NULL)
		return NULL;
	if (s1 == NULL)
		return mx_strdup(s2);
	if (s2 == NULL)
		return mx_strdup(s1);
	int povit = 0;
	char *p = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

	for (int nz = 0; s1[nz] != '\0'; nz++, povit++)
		p[povit] = s1[nz];
	for (int nz = 0; s2[nz] != '\0'; nz++, povit++)
		p[povit] = s2[nz];
	return p;
}
