
#### Physical Animation for AI;
Every character mesh in unreal engine has a physical asset also known as a ragdoll. On enemy defeated I wanted to create a realistic death animation without repeating the same animation over and over. I decided to use ragdoll to implement that. When enemy’s health is equal to 0 it starts to simulate physics, the result was unnatural death because mesh couldn’t hold the position of bones ant it looked like a bag of meat without bones.
![noprofile](https://github.com/Bubbleverus/Gensis_Prototype/blob/master/Leyla_Screenshots/noprofilesimulatephysics.png)
This is where I used unreal experimental class PhysicalAnimationComponent.
![warning](https://github.com/Bubbleverus/Gensis_Prototype/blob/master/Leyla_Screenshots/physicalanimationwarning.png)
I added a custom profile to a physical asset that allowed it to simulate physics the same as human body would fall.
![withprofile](https://github.com/Bubbleverus/Gensis_Prototype/blob/master/Leyla_Screenshots/withprofilesimulatephysics.png)
I setup such variables as oriental strength and velocity. In order to apply this profile to all bones of our character I used physical animation component I added to the enemy’s class and then hit simulate physics to all bones.
![blueprint](https://github.com/Bubbleverus/Gensis_Prototype/blob/master/Leyla_Screenshots/physicalanimation.png)
Also spawn blood particle for dramatic effect. After all this steps each time you defeat an enemy you get a different result of falling and laying position on the ground.
![bag](https://github.com/Bubbleverus/Gensis_Prototype/blob/master/Leyla_Screenshots/bloodandgore.png)
Link to see AI death in action:
https://youtu.be/aLLyAie9uhM

#### Animation blueprints and blends for Boss and Enemy AI;
I setuped all animations blueprints and blends for enemy characters, and some blends for characters if needed. 
