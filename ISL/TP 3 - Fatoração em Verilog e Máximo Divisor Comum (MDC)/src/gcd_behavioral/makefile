TARGET   = gcd
SOURCE   = gcd_top.v gcd_engine.v bin_to_bcd.v hex_to_7seg.v gcd_tb.v
IVERILOG = iverilog
VVP      = vvp
WAVE     = gtkwave
 
all: $(TARGET).vcd
 
$(TARGET).vvp : $(SOURCE)
	$(IVERILOG) -o $(TARGET).vvp $(SOURCE)
#
$(TARGET).vcd : $(TARGET).vvp
	$(VVP) $(TARGET).vvp
#
view : all
	$(WAVE) $(TARGET).vcd
#
clean :
	rm *.vvp *.vcd
