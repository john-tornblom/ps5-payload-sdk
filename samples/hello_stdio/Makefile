ifndef PS5_PAYLOAD_SDK
    $(error PS5_PAYLOAD_SDK is undefined)
endif

PS5_HOST ?= ps5
PS5_PORT ?= 9020

ELF := hello_stdio.elf

CC := clang
LD := ld.lld

CFLAGS := --sysroot $(PS5_PAYLOAD_SDK) -fPIC -mcmodel=large
LDADD  := -lSceLibcInternal

all: $(ELF)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(ELF): main.o
	$(LD) -static -o $@ \
	      -T $(PS5_PAYLOAD_SDK)/ldscripts/elf_x86_64.x \
	      -L$(PS5_PAYLOAD_SDK)/usr/lib \
	      $^ $(PS5_PAYLOAD_SDK)/usr/lib/crt1.o \
	      $(LDADD)

clean:
	rm -f *.o $(ELF)

test: $(ELF)
	nc -q0 $(PS5_HOST) $(PS5_PORT) < $^

