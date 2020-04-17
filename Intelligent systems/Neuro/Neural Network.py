#https://towardsdatascience.com/how-to-build-your-own-neural-network-from-scratch-in-python-68998a08e4f6
#https://neurohive.io/ru/machine-learning-cases/kak-sozdat-nejronnuju-set-s-nulja-na-jazyke-python/

import numpy as np
import math

class Neural_Network(object):
  def __init__(self):
  #parameters
    self.inputSize = 3
    self.outputSize = 1
    self.hiddenSize = 3

  #weights
    self.W1 = np.random.randn(self.inputSize, self.hiddenSize) # (3x2) weight matrix from input to hidden layer
    self.W2 = np.random.randn(self.hiddenSize, self.outputSize) # (3x1) weight matrix from hidden to output layer

  def forward(self, X):
    #forward propagation through our network
    self.z = np.dot(X, self.W1) # dot product of X (input) and first set of 3x2 weights
    self.z2 = self.sigmoid(self.z) # activation function
    self.z3 = np.dot(self.z2, self.W2) # dot product of hidden layer (z2) and second set of 3x1 weights
    o = self.sigmoid(self.z3) # final activation function
    return o

  def sigmoid(self, s):
    # activation function
    return 1/(1+np.exp(-s))

  def sigmoidPrime(self, s):
    #derivative of sigmoid
    return s * (1 - s)

  def backward(self, X, y, o):
    # backward propagate through the network
    self.o_error = y - o # error in output
    self.o_delta = self.o_error*self.sigmoidPrime(o) # applying derivative of sigmoid to error

    self.z2_error = self.o_delta.dot(self.W2.T) # z2 error: how much our hidden layer weights contributed to output error
    self.z2_delta = self.z2_error*self.sigmoidPrime(self.z2) # applying derivative of sigmoid to z2 error

    self.W1 += X.T.dot(self.z2_delta) # adjusting first set (input --> hidden) weights
    self.W2 += self.z2.T.dot(self.o_delta) # adjusting second set (hidden --> output) weights

  def train(self, X, y):
    o = self.forward(X)
    self.backward(X, y, o)

  def saveWeights(self):
    np.savetxt("w1.txt", self.W1, fmt="%s")
    np.savetxt("w2.txt", self.W2, fmt="%s")
    
  def loadWeights(self):
    self.W1 = np.loadtxt("w1.txt")
    self.W2 = np.loadtxt("w2.txt")

  def predict(self, data):
    print("\nPredicted data based on trained weights: ")
    print("Input: \n" + str(data))
    print("Output: \n" + str(round( self.forward(data) * 10 )))


print('Intellegence systems lab 3 by student Ibetullov Yuriy 8VM71 group. \nNeural Network variant 11. \n\n')

options = ["0. Neural Network Training\n",
           "1. Predict\n", 
           "2. Exit\n"]

NN = Neural_Network()

while True:
    ans = input('Choose option: \n' + ''.join(options))
    if ans == "0":
        X=np.array(([1,1,0],[1,0,1],[0,0,1],[0,1,0],[0,1,1],[0,0,1],[0,1,0],[1,1,1],[0,0,0]), dtype=float)
        y=np.array(([0.1],[0.1],[0.2],[0.3],[0.2],[0.3],[0.3],[0.1],[0.2]), dtype=float)
        
        for i in range(1001): # trains the NN 1,000 times
            if i % 100 ==0:
                print("# " + str(i) + "\n")
                print("Input: \n" + str(X))
                print("Actual Output: \n" + str(y))
                print("Predicted Output: \n" + str(NN.forward(X)))
                print("Loss: \n" + str(np.mean(np.square(y - NN.forward(X))))) # mean sum squared loss
                print("\n")
            NN.train(X, y)

        NN.saveWeights()
        print('Weight matrix from input to hidden layer:\n' + str(NN.W1))
        print('Weight matrix from hidden to output layer:\n' + str(NN.W2))

    elif ans == "1":
        NN.loadWeights()

        a, b, c = input("input params (in format XXX): ")
        NN.predict(np.array(([int(a),int(b),int(c)]), dtype=float))

        more = input('Continue (y/n)? : ')
        if more.lower() != 'y':
            break


    elif ans == "2":
        break

    else:
        print("Wrong input.")
    
    print("\n-----------------------\n")


