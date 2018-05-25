# Wii Boot Process
as explained by someone who has no idea what they're getting themselves into
## boot0
Hardware is reset, power button is pressed, code execution jumps to an on-dye bootrom (aka boot0) at 0xFFFF0000.

How that works I don't understand and really don't care.

Very basic explanation, fill in details later:

Both boot0 and boot1 are unfixable, so we want as little overhead as possible. boot0 initializes the bare minimum, loads the first 48 "pages" of NAND, and decrypts boot1, which does its own thing.

We are very limited on space which is why we have 3 boot sections. boot0 is limited to 4KB(?), boot1 is limited to 96K, and then boot2 is free to be as big as it wants.

boot0 cannot be updated without making a new CPU, boot1 cannot be updated without programming a new OTP (hash is stored there and cannot be modified). boot2 can be updated, but only with a valid signature(?) or some system flaw that 90% of Wiis just happen to have.

TODO: finish this shit

<!---
* Set-up basic registers
  * R1, R4, R11 (x2), LR = 0
  * Stack Pointer = 0xD417C00 # top of SRAM(?)
  * trunk jump to main, panic instruction after in case anything goes wrong
--->
