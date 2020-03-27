Megan Work
Project 5 Alt
CS 120

This project is designed to

In Water_Monster_Main (line 74 //TODO: make sure correct
, when the user selects for it to be meal time for the monster, the populated vector is looped through and has a call to eat_person
in each iteration. This is not an example of polymorphism. Calling the function eat_person has no effect on whether the call is in relation
to a lake monster or sea monster. The function does not require an overridden method for the children.

Unlike the other option the user has, scare time (line 80). //TODO: check at end
When the function scare is called, it requires an overridden method for both the sea monster and lake monster. They both inherited the method to scare, but
they have implemented an override their subclasses to have different ways to utilize the method.

This can be seen again in Darkness_Monster_Main on line 33 where the scare method is called again for both the closet monsters and the monsters under the bed.
They have different uses for the scare method which have been overridden within their subclasses.

In the same file, on line 49, we see an example of something which is NOT polymorphism. Similarly to the eat_person calls with the water monsters, the
poke_eye method between the closet monsters and bed monsters does not need to be overrode for each subclass. This method exactly the same for both, so they can simply
just use the method as it was when they inherited it.
