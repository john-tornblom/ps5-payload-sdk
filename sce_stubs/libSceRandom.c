
asm(".global sceRandomGetRandomNumber\n"
    ".type   sceRandomGetRandomNumber, @function\n"
    ".symver sceRandomGetRandomNumber, sceRandomGetRandomNumber@@0x3C8EE32198F8A5C1\n"
    "sceRandomGetRandomNumber:\n");
