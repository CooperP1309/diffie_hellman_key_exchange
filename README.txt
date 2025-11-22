-----
Diffie-Hellman Key Exchange - Practical Assignment - Information Security

By Cooper Peek; StuID: 22093312

Created 29/09/2025
-----

---- How To Use ----

Ensure that the binary has execution permissions. In a Linux terminal, use "cd" to navigate to the program folder 
that contains the binary file ("dh_kx") and invoke the following:

	sudo chmod +x dh_kx

You are now ready to run the program. Use the following syntax to run the program:

	./dh_kx

Once running, prompts will guide you through your options.

Main Note: when inputting manually, you are to input p, follwed by xA and xB.
		   Once those are inputted, you will be given a range of primitive roots to
		   choose from.
----


---- General Architecture ----

	CALCULATING THE PRIMITIVE ROOT:

		Though the definition of a primitive root is simple (where p is a pre-chosen prime number):

			A positive integer greater than 0 and less than p which, when multiplied by itself between 1 and p-1 times, and modulus against p each time, produces every number from 1 to p-1.

		We could simply check that no product of every possible g^k mod p occurs more than once, but this is computationally taxing. Especially when p can be as great as 97 as per the requirements for this assignment.

		Rather, I've opted to use Lagrange's Theorem to implement a simpler alogrithm. The theorem goes as follows:

			"• If G is finite group and H is a subgroup of G, then
			 a) |H| divides |G|.
			 b) The number of distinct left (right) cosets of H in G is |G|/|H|"

			Source:

				CUEMATH, Lagrange Theorem.
					https://www.cuemath.com/algebra/lagrange-theorem/

		In my terms, regarding finding the primitive root:

			The amount of possible outcomes from repeating: "g^k mod p" (where k is a changing element in the muliplicative group Z*p) and where g is a fixed element the multiplicative group Z*p is going to be a factor of p-1 every time.

			Example: 

			p = 13; Thus p-1 = 12. If we test each element between 1 and 12 as the primitive root, the number of different elements produced each time using "g^k mod p" is always going to be a factor of 12...

				12, 6, 4, 3, 2, 1

			(Note: The number of different elements produced is actually known as the order)

		How I implement this:

			We know that the start product of each order is always 1 (as g^0 mod p is always 1, thus defining the cycle). 

			Therefore, we only need to calculate g ^ k mod p, where k is a different factor of p-1 each time. 

			If we get 1 as a product, we know that instance of g is NOT a primitive number, as the order of products from that instance of g only go as far as whatever factor of p-1 was used.

		The psuedo code:

			get factors of (p-1)

			for each multiplicate element (i.e. numbers 1 to p-1) = g:

				for each factor of (p-1) = k:

					if g^k mod p == 1

					Not a primitive root; continue;

				if execution makes it here, g is a primitive root

----
