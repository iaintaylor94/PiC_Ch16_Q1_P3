// This program copies one file to another

#include <stdio.h>

int main(void) {

  char inName[64], outName[64];
  FILE *in, *out;
  int c;

  // Get file names from the user
  printf ("Enter the name of the file to be copied: ");
  scanf("%63s", inName);
  printf ("Enter the name of the output file: ");
  scanf ("%63s", outName);

  // Open input and output files
  if ((in = fopen (inName, "r")) == NULL) {
    printf ("Can't open %s for reading.\n", inName);
    return 1;
  }

  if ((out = fopen (outName, "w")) == NULL) {
    printf ("Can't open %s for writing.\n", outName);
    return 2;
  }

  // Copy in to out
  while ((c = getc(in)) != EOF)
    putc (c, out);

  // Close open files
  fclose (in);
  fclose (out);

  printf ("File has been copied\n");
  
  return 0;
}