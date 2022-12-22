// Registrador de Deslocamento conforme modelo mostrado 
// no livro Fundamentals of Logic Design, 7ª Edição, pg.382
module ShiftRegister_8bit(data, sh, load, clk, serial_out, parallel_out);
  input [7:0]data;
  input sh;
  input load;
  input clk;
  output serial_out;
  output [7:0]parallel_out;
  
  // Resultado dos multiplexadores
  wire wire_m7;
  wire wire_m6;
  wire wire_m5;
  wire wire_m4;
  wire wire_m3;
  wire wire_m2;
  wire wire_m1;
  wire wire_m0;
  
  // Resultado dos Flip-Flop
  wire wire_dff7;
  wire wire_dff6;
  wire wire_dff5;
  wire wire_dff4;
  wire wire_dff3;
  wire wire_dff2;
  wire wire_dff1;
  wire wire_dff0;
  
  // Instanciando os multiplexadores
  mux_4to1 m7(.in00(wire_dff7), .in01(data[7]), .in10(wire_dff0),
              .in11(wire_dff0), .Sh(sh), .L(load), .out(wire_m7));
  
  mux_4to1 m6(.in00(wire_dff6), .in01(data[6]), .in10(wire_dff7),
              .in11(wire_dff7), .Sh(sh), .L(load), .out(wire_m6));
  
  mux_4to1 m5(.in00(wire_dff5), .in01(data[5]), .in10(wire_dff6),
              .in11(wire_dff6), .Sh(sh), .L(load), .out(wire_m5));
  
  mux_4to1 m4(.in00(wire_dff4), .in01(data[4]), .in10(wire_dff5),
              .in11(wire_dff5), .Sh(sh), .L(load), .out(wire_m4));
  
  mux_4to1 m3(.in00(wire_dff3), .in01(data[3]), .in10(wire_dff4),
              .in11(wire_dff4), .Sh(sh), .L(load), .out(wire_m3));
  
  mux_4to1 m2(.in00(wire_dff2), .in01(data[2]), .in10(wire_dff3),
              .in11(wire_dff3), .Sh(sh), .L(load), .out(wire_m2));
  
  mux_4to1 m1(.in00(wire_dff1), .in01(data[1]), .in10(wire_dff2),
              .in11(wire_dff2), .Sh(sh), .L(load), .out(wire_m1));
  
  mux_4to1 m0(.in00(wire_dff0), .in01(data[0]), .in10(wire_dff1),
              .in11(wire_dff1), .Sh(sh), .L(load), .out(wire_m0));
  
  // Instanciando os 8 Flip-Flops
  FlipFlopD dff7(.clk(clk), .D(wire_m7), .Q(wire_dff7));
  FlipFlopD dff6(.clk(clk), .D(wire_m6), .Q(wire_dff6));
  FlipFlopD dff5(.clk(clk), .D(wire_m5), .Q(wire_dff5));
  FlipFlopD dff4(.clk(clk), .D(wire_m4), .Q(wire_dff4));
  FlipFlopD dff3(.clk(clk), .D(wire_m3), .Q(wire_dff3));
  FlipFlopD dff2(.clk(clk), .D(wire_m2), .Q(wire_dff2));
  FlipFlopD dff1(.clk(clk), .D(wire_m1), .Q(wire_dff1));
  FlipFlopD dff0(.clk(clk), .D(wire_m0), .Q(wire_dff0));
  
  // a saída vai ser o conteúdo do último flip-flop
  assign serial_out = wire_dff0;

  // parallel out
  assign parallel_out[7] = wire_dff7;
  assign parallel_out[6] = wire_dff6;
  assign parallel_out[5] = wire_dff5;
  assign parallel_out[4] = wire_dff4;
  assign parallel_out[3] = wire_dff3;
  assign parallel_out[2] = wire_dff2;
  assign parallel_out[1] = wire_dff1;
  assign parallel_out[0] = wire_dff0;

endmodule

// Multiplexador 4-1
// 4 inputs, 2 sinais de seleção, 1 output
module mux_4to1(in00, in01, in10, in11, Sh, L, out);
  input in00, in01, in10, in11, Sh, L;
  output out;
  
  assign out = ((~Sh & ~L) & in00) | ((~Sh & L) & in01) | ((Sh & ~L) & in10) | ((Sh & L) & in11);
  
endmodule

// Implementação Estrutural do Flip-Flop tipo D
// utilizando o modelo de Katz (p. 271)
module FlipFlopD(clk, D, Q);
  input clk, D;
  output Q;
  wire nD, nC, R_M, S_M, R_S, S_S, Q_M, Qb_M, Q_S, Qb_S;
  
  not notD(nD, D);
  not notC(nC, clk);
  
  and and_M1(S_M, D, nC);
  and and_M2(R_M, nD, nC);
  Latch_SR Master(Q_M, Qb_M, S_M, R_M);
  
  and and_S1(S_S, Q_M, clk);
  and and_S2(R_S, Qb_M, clk);
  Latch_SR Slave(Q_S, Qb_S, S_S, R_S);
  
  assign Q = Q_S;
  
endmodule

// Latch SR
module Latch_SR(Q, Qbar, S, R);
  input S, R;
  output Q, Qbar;
  
  nor nor1(Q, R, Qbar);
  nor nor2(Qbar, S, Q);
endmodule