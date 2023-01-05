ifndef PS5_PAYLOAD_SDK
    $(error PS5_PAYLOAD_SDK is undefined)
endif

PS5_HOST ?= ps5
PS5_PORT ?= 9020

ELF := list_files.elf

CC ?= cc
LD ?= ld

CFLAGS := -isysroot $(PS5_PAYLOAD_SDK) -static
LDADD  := -lkernel_web -lSceLibcInternal

all: $(ELF)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(ELF): main.o
	$(LD) -o $@ \
	      -T $(PS5_PAYLOAD_SDK)/linker.x \
	      -L$(PS5_PAYLOAD_SDK)/usr/lib \
	      $^ $(PS5_PAYLOAD_SDK)/usr/lib/crt1.o \
	      $(LDADD)

clean:
	rm -f *.o $(ELF)

test: $(ELF)
	nc -q0 $(PS5_HOST) $(PS5_PORT) < $^

