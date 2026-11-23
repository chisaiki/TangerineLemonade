Build a simple lemonade stand game (management game)
where I have a duck selling lemonade

Random customers spawn
3 classes of customers
- Big Tipper
- Karen
- Normal
- Charity

Lemons spoil over night?
Sugar needs to be bought
Lemons need to be bought
Call mom for more money (random amount)

--- 

Core loop: customer arrives, read input, update the state, draw the frame, repeat.

## To Do

tick() does three things:
Rolls s.rng to decide how many customers arrive (0–2, say) and adds makeCustomer(s) results to the queue.
Lowers each waiting customer's patience.
Removes customers whose patience hits 0 and logs their angry_lines (this is where Karen gets fun).