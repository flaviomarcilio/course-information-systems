// Implementação Comportamental do Flip-Flop tipo D
module DFlipFlop(clk, D, Q);
  input clk, D;
  output reg Q;
  always @(posedge clk)
    begin
      Q = D;
    end
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