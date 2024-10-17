% Facts

% Animals
animal(lion).
animal(tiger).
animal(elephant).
animal(dog).
animal(cat).
animal(eagle).
animal(sparrow).
animal(shark).

% Mammals
mammal(lion).
mammal(tiger).
mammal(elephant).
mammal(dog).
mammal(cat).

% Birds
bird(eagle).
bird(sparrow).

% Rules

% All mammals are animals
is_animal(X) :- mammal(X).
is_animal(X) :- bird(X).

% Check if an animal is a mammal
is_mammal(X) :- mammal(X).

% Check if an animal is a bird
is_bird(X) :- bird(X).

% Find all animals
all_animals(Animals) :- findall(X, animal(X), Animals).

% Find all mammals
all_mammals(Mammals) :- findall(X, mammal(X), Mammals).

% Find all birds
all_birds(Birds) :- findall(X, bird(X), Birds).

% Query Examples
% 1. Check if something is an animal
% ?- is_animal(dog).
% Expected output: true.

% 2. Check if something is a mammal
% ?- is_mammal(lion).
% Expected output: true.

% 3. Check if something is a bird
% ?- is_bird(eagle).
% Expected output: true.

% 4. List all animals
% ?- all_animals(Animals).
% Expected output: Animals = [lion, tiger, elephant, dog, cat, eagle, sparrow, shark].

% 5. List all mammals
% ?- all_mammals(Mammals).
% Expected output: Mammals = [lion, tiger, elephant, dog, cat].

% 6. List all birds
% ?- all_birds(Birds).
% Expected output: Birds = [eagle, sparrow].
