`ifndef REGISTERS_V
  `define REGISTERS_V

  `include "utils.vh"

  module registers# (parameter DWIDTH = 32, parameter RSELWIDTH = 5) (
      output wire [DWIDTH-1:0] read_data1, read_data2,
      input  wire [DWIDTH-1:0] write_data,
      input  wire [RSELWIDTH-1:0] read_address1, read_address2, write_address,
      input  wire write_en, clk
    );

    reg [DWIDTH-1:0] regbank [0:DWIDTH-1];                                    // 32 registers of 32 bits
    reg [DWIDTH-1:0] data1, data2;

    // assynchronous way:
    always @(*) begin
      if(read_address1 == 0) begin                                            // zero is a 'special' register in MIPS!
        data1 = 0;                                                            // put output in zero
      end else if((read_address1 == write_address) && write_en) begin         // if from 'read register1' and 'write register'
        data1 = write_data;                                                   // write data from data memory
      end else begin
        data1 = regbank[read_address1][DWIDTH-1:0];                           // write data output from registers bank (indexed by rreg1)
      end
    end

    always @(*) begin
      if(read_address2 == 0) begin                                            // zero is a 'special' register in MIPS!
        data2 = 0;                                                            // put output in zero
      end else if((read_address2 == write_address) && write_en) begin         // if from 'read register1' and 'write register'
        data2 = write_data;                                                   // write data from data memory
      end else begin
        data2 = regbank[read_address2][DWIDTH-1:0];                           // write data output from registers bank (indexed by rreg1)
      end
    end

    // synchronous way:
    always @(posedge clk) begin
      if(write_en && (write_address != 0)) begin                              // if there's a write req. and the reg. is not the zero reg.:
        regbank[write_address][DWIDTH-1:0] <= write_data;                     // write data into register bank
      end
    end

    // Update outputs:
    assign read_data1 = data1;
    assign read_data2 = data2;

  endmodule

`endif // REGISTERS_V
