Genesis-X implementation work
-----------------------------

*Louis Bennette*
 ---
 
**Aiming Movement and Shooting:**

Early on in development I was tasked with player movement, specifically player alignment while aiming. 
The game is a 3rd person shooter with 3rd person shoulder zoom when aiming. 
The original design was to have a free camera where the player model is not attached to the camera movement. Only when the player either aims or fires the player model is turned to face the same direction as the camera. 
In order to keep the other connected players in sync with the character’s bearing I use the player movement component which handles the multiplayer side.
The player movement component has a max and min rotation rate to move in a direction requires inputting a vector for the desired world direction. Because I did want to use the rotation rate feature of the player movement but I didn't want the player to move. I just gave the player a very small vector in the direction the camera was facing. This triggers the synced player movement across clients but the player only moves by a tiny amount so appears still.

The players have the choice between 4 playable characters and all these characters are children of the Ch_Base class where all our common player specific code was implemented.
Early on in the development of the game all game mechanics and scene environment was tested using the Ch_Base, and as a result early aiming and animation work was done for this class too.
Leyla found some shooting and aiming animations created for the default unreal player model. The animations had to be remapped to the unreal skeleton class and it’s aim animation had to be blended into the idle animation for each weapon.  This was handled with boolean field in the player base class, “is_aim” and “firing”. These are checked by the animation component to blend in the aim animations.

![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_Img.png)
The weapons that the player holds were attached to the skeleton using a socket on the right hand of the player. The weapons themselves need to have an offset so that they sit neatly in the model’s hands and the weapons also have a barrel exit marker which is used for firing bullets from the correct point.
 (See equip weapon blueprint below)

We also wanted to make our own aiming system, this was in development earlier on in the project and was later replaced. The reason we decided to implement our our own aiming system is because using a forward vector from the gun barrel or the player model would shoot the target at an offset equal to the camera offset. 
![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_Img2.png)
The aiming system draws a ray from the camera forward vector to find the collision point then the character is adjusted so the character forward vector faces the collision point. When the gun is fired another ray is cast from the exit of the barrel. Sometimes the camera can have a clear line of sight on the target but the character model has an obstacle between it and the target.
(See turn to camera function in blueprints below)



**Raven Healing Ability:**

Each character required a special ability, I was tasked with the healing ability, this is done by firing a ray from the camera to a game actor, player character or the floor. 
The player classes are the only actors that need to be validated as in range. 
I loop over the players and check if they are in range of the collision point of the healing ability. If they are I increment their health. A heal cannot increase the player’s health above their max health.
(See raven healing function in blueprints below)



**World Layout:**

Later on in the project I was responsible for dressing the scene. The game story has a master AI that created the world around the players and can fabricate and destroy, virtual objects and entities in the game. The level has multiple triggers which spawn in AI by using an animation constructed from particle emitters. 

![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_Img3.png)
 

I placed the opponents across the map by marking their spawn points with a custom spawn object I place in the scene. When a player enters the trigger, the level blueprint spawns particles and and AI actor with the transform of the spawn location.
(See AI spawning in blueprints below)

Additionally I set up the shops with their sellables and lootables and I placed pickups and weapons across the map.

---
![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_BP1p1.png)
Turn to face camera function part 1
 
---
![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_BP1p2.png)
Turn to face camera function part 2

---
![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_BP1p3.png)
Turn to face camera function part 3
 
 ---
![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_BP2.png)
Equip weapon in right hand

---
![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_BP3.png)
Raven’s Healing ability

---
![enter image description here](https://raw.githubusercontent.com/Bubbleverus/Gensis_Prototype/master/Louis_Screenshots/Gen_BP4.png)
AI spawning in Combat Level
