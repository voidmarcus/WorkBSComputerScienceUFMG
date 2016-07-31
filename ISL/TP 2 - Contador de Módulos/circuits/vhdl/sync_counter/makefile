ifeq '$(TIME)' ''
  TIME := 10000ms
endif
ifeq '$(NOWAVE)' ''
  ifeq '$(WAVECMD)' ''
    ifeq '$(WAVEFILE)' ''
	  WAVEFILE := waves.vcd
	endif
	WAVECMD := --vcd=$(WAVEFILE)
  endif
endif

# Sources: --------------------------------------------------------------------
SOURCES = ./sync_counter_top.vhd \
					../common/flipflop_jk.vhd \
					../common/dec_bcd_to_7seg.vhd

# Testbench: ------------------------------------------------------------------
TESTBENCH = ./sync_counter_tb.vhd

# Top Entity: -----------------------------------------------------------------
TOPENTITY = sync_counter_tb

# set vhdl standard
STANDARD = 02

.default: all

.phony: compile run runw test all clean

all:  $(TOPENTITY) run

run: $(TOPENTITY) $(SOURCES)
	ghdl -e --std=$(STANDARD) --ieee=synopsys -fexplicit --workdir=work $(TOPENTITY)
	ghdl -r $(TOPENTITY) $(WAVECMD) --stop-time=$(TIME)

# run ghdl on windows (it is broken with actual ghdl version 0.26)
runw:
	-rm -r work
	-mkdir work
	ghdl -c --std=$(STANDARD) --ieee=synopsys -fexplicit --workdir=work $(TESTBENCH) $(SOURCES) -r $(TOPENTITY) $(WAVECMD) --stop-time=$(TIME)

$(TOPENTITY):  $(SOURCES)
	-mkdir work
	ghdl -a --std=$(STANDARD) --ieee=synopsys -fexplicit --workdir=work $(TESTBENCH) $(SOURCES)

test:
	ghdl -a --std=$(STANDARD) --ieee=synopsys -fexplicit --workdir=work $(TESTBENCH) $(SOURCES)

compile:  clean $(TOPENTITY)

clean:
	-rm $(TOPENTITY)
	-rm -r work
	-rm *.vcd
	-rm ouput.txt
