# Abstract
In this project my role was to create and work with:
#### Inventory system with Weapon Stats;
In this project, I did a similar inventory I did before except it now has more functionality and more complicated construction script because every time you press “I” to open inventory it creates four different canvas panels(boxes) holding different items and displaying weapon stats. Items are separated by enum type that helps place them in the right box. The weapon stats box holds information taken from weapon class. Because of enumeration structure I added to hold types, when our player pickup items they go to the right box in inventory, also we have USE button that depending on which type of item you want to use it calls different events. For weapon you equip them, for potions they heal, buff our player and then disappear when used, if its regular supplies we have in our game you can only sell these items. Drop buttom drops selected items in front of the player.
To update information in widget I used to functions list items and list weapon.
List weapon displays weapon information.
List items created a button with image of items in dofferent windows depending on type, also it’s a scroll box so If number of items is big we can scroll with our mouse down and up.

#### Trading system;
I made a trading system where players can exchange items with seller for money. Our currency was ammo shells, because it fitted to the whole theme in our game. First I made an actor to represent our seller, that actor also holds an array called Seller Inventory based on item structure I did before for items to hold all information we needed (struct) and every time payer overlap with the collision box the trading widget is created. When the UI widget is created, it holds information from both seller and player. All buy sell functions are running in real time because functions are updated after each time sell/buy button is pressed. On clicked sell/buy, it checks if there an item exists in array, and check can player/seller actually buy/sell it by checking how many ammo shells they have. Then the selected item is added to player/seller inventory array, and ammo shells are subtracted from player/seller, and they added to our player/seller wallet and that selected item is deleted from inventory it was before. I also used clamp and set the minimum for seller/player money equal to 0. After that three functions List Player Items, List Seller Items, List Ammo Shells are called to refresh information in trading boxes.
#### Lootbox system;
Loot box has the same principle as trading system except it doesn’t linked to the currency. Player can place as many items as he desires. 
#### Use items from inventory;
Use button allows us to use selected item. On clicked use it checks if selected item exists then checks enum type, if its potion it goes through another enumeration structure I added it specially for potions and in order to make artists life easier. They don’t need to program, just select type of item and which type of potion is that. If item type is weapon, it checked are we holding a weapon and whether the weapon the player is holding the same as the weapon we want to equip. if false it destroys the attached to our socket actor and attaches selected weapon class actor. 
#### Ability: Taunt;
In our game there are four characters with different abilities. I made taunt ability for character named Talos. On player hit ability button “E”,first it checks are there any AI enemies within distance of 600 meters and then gets their AI controller set their focus on our player, it also spawns a particle for effect that ability is used. AI then set his focus on Talos and as soon as that happens he finds location near our player and attack him. 
#### AI enemy and boss;
#### Add sounds to weapons;
#### Item structures;
#### Physical Animation for AI;
#### Animation blueprints and blends for Boss and Enemy AI;
