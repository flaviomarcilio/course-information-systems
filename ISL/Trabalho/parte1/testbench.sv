// Code your testbench here
// or browse Examples
module testbench;
  reg clk,D;
  wire Q;
  // Modelo Estrutural
  FlipFlopD DFF(clk,D,Q);
  
  // Modelo Comportamental
//   DFlipFlop DFF(clk, D, Q);
  initial
    begin
      clk=0;
      forever #1 clk=~clk;
    end
  initial
    begin
      $dumpfile("dump.vcd");
      $dumpvars(1,testbench);
      $monitor($time," clk = %b,D = %b,Q = %b",clk,D,Q);
      D=0;
      #2 D=1;
      #2 D=0;
      #2 D=1;
      #2 D=0;
      #2 D=0;
      #2 D=1;
      #2 D=0;
      #4 $finish;
    end
  endmodule
  