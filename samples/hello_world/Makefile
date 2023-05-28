ifndef PS5_PAYLOAD_SDK
    $(error PS5_PAYLOAD_SDK is undefined)
endif

PS5_HOST ?= ps5
PS5_PORT ?= 9020

ELF := hello_world.elf

CC := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-payload-cc
LD := $(PS5_PAYLOAD_SDK)/host/x86_64-ps5-payload-ld

CFLAGS := -O2
LDADD  := -lkernel_web -lSceLibcInternal

all: $(ELF)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(ELF): main.o
	$(LD) $^ $(LDADD) -o $@

clean:
	rm -f *.o $(ELF)

test: $(ELF)
	nc -q0 $(PS5_HOST) $(PS5_PORT) < $^

