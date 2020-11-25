# FPS Simulator
This is a simple **FPS simulator** 
There are no graphics and this programs runs on randomization in order to simulate the randomness of an actual FPS game with real players.  
This game is simulating --> It simulates 5 attackers fighting 5 defenders. The defenders have to try and plant the bomb and protect it for three rounds. If they attackers defuse it they lose. After 16 rounds its halftime and they switch sides.
If one team dies then the other team wins. First team to win sixteen rounds wins the game.

## **Configuration**

In the `config.h` file you are able to change settings of the game such as the amount of players, or the chance to join an existing match. Each player is given a gun and 100 health. They have a chance of getting 1 out of 5 gun. Each gun has unique stats, such as more ammo in one or more damage in another.

## **How it works**
**Matchmaking**
We will then **matchmake** by getting all the eligible players from the teams. If a player is dead then it will not be eligible and will not be matchmaked. If there is an extra player left over then it will have a chance to be added to an existing fight. This extra player that joined will have a chance to Plant or Defuse the bomb if already planted. If the bomb is planted for three fights in a row then the team that planted wins. If the bomb is defused the team that defused wins. 
**Fighting**
A fighter has a chance to shoot the planter or defuser before they plant or defuse. For the fighting both bots fight using randomization until they run out of ammo. If both players run out of ammo or one dies the fight is over. If a player dies they will no longer be in the round, but if both players run out of ammo they can still fight. Once each fight is done you reset the ammo and matchmake again. After the 16th round both teams switch sides. 
**How they win**
This is repeated until one team has scored 16 points. After each round there is a “Round Feed” and stats printed for that round. After the game the stats for the game is printed which includes score, damage, deaths, kills, etc.

**TODO**
 - Make scoreboard easier to understand (Will come back after learning rendering) 
 - Fix defuser and planting scenarios (Sometimes the same player plants or defuses 5 or more times) 
 - Balance weapons. 
 - Implement skill level
