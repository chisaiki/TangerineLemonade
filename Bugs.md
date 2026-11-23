# Some Bugs I Found

## Minor 

- In my gameFunctions implementation file, I was getting the error: 

```cpp
class "GameState" has no member "lemons"
```

I automatically assumed that because I deleted the "all libraries" header file, it was causing inclusion errors. So I went to the header file and tried to add the gameStruct header, only to realize it was already there. So then I went back and reread the function prototype and realized I was only passing a GameState object and not the struct that was holding the values for lemons, sugar, and stock (Struct Inventory). I thought about adding in manually another parameter for the Inventory object but, when I checked the header for game struct, I noticed there was already an instance of inventory in the GameState struct. So finally I went backt to the gameFunctions.cpp, and used the right syntax to access inventory within gamestate. 

```cpp
game_block.lemons -> game_block.inventory.lemons 
```