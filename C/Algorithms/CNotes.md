## C quick and dirty notes...

...about things I've unfortunately forgotten and now slowly start remembering again. 

1. I won't be casting `malloc` calls from now on as a personal preference. The [topic][stack_malloc] is some-what 
   flamewar-y so whatever position chosen can be argued about.

2. Basically every entry in [C-faq 6. Arrays and Pointers][cfaq6]. Always troubled by the weird relationship arrays 
   and pointers *appear* to have.

3. Casting from `char` to `int`, cool. Casting from `char *` to `int *`, daft. `sizeof(char)` is `1`, of `int`, at least 
   `2` (and most likely `4`). You read junk and why do that to yourself?

[cfaq6]: http://c-faq.com/aryptr/index.html
[stack_malloc]: https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc
