////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores printing to file.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	FILE * fptr;

	fptr = fopen ("matrix_blue-pill-prelude", "a");

	fprintf (fptr, "Morpheus: Do you believe in fate, Neo?\n\n");
	fprintf (fptr, "Neo: No.\n\n");
	fprintf (fptr, "Morpheus: Why?\n\n");
	fprintf (fptr, "Neo: Because I don't like the idea that I'm not in control of my own life.\n\n");
	fprintf (fptr, "Morpheus: I know...*exactly* what you mean. Let me tell you why you're here. You're here because you know something. What you know, you can't explain. But you feel it. You've felt it your entire life. That there's something *wrong* with the world. You don't know what it is, but it's there... like a splinter in you're mind, driving you mad. It is this feeling that has brought you to me. Do you *know* what I'm talking about?\n\n");
	fprintf (fptr, "Neo: The Matrix?\n\n");
	fprintf (fptr, "Morpheus: Do you want to know... *what* *it* is...?\n\n");
	fprintf (fptr, "Neo nods\n\n");
	fprintf (fptr, "Morpheus: The Matrix is everywhere. It's all around us, even in this very room. You can see it when you look out your window or when you turn on your television. You can feel it when you go to work, when you go to work, when you pay your taxes. The Matrix is the world that has been pulled over your eyes, to blind you from the truth.\n\n");
	fprintf (fptr, "Neo: What truth?\n\n");
	fprintf (fptr, "Morpheus: That you are a slave, Neo. Like everyone else, you were born into bondage, born into a prison that you cannot smell or taste or touch. A prison... for your mind... Unfortunatly, no one can be... *told* what the Matrix is. You have to see it for yourself.");

	fclose (fptr);

	return 0;
}
