from tensorflow.python.keras.models import model_from_json

from Lab_6.Lab_6_1.python.subtask_1 import X_test, Y_test

json_file = open("/Lab_6/Lab_6_1/models/mine/mnist_model.json", "r")

loaded_model_json = json_file.read()

json_file.close()

loaded_model = model_from_json(loaded_model_json)

loaded_model.load_weights("D:/BSU-Projects/6th-Term/Neural-Net/Lab_6/Lab_6_1/models/mnist_model.h5")
loaded_model.compile(loss="categorical_crossentropy", optimizer="SGD", metrics=["accuracy"])
scores = loaded_model.evaluate(X_test, Y_test, verbose=0)

print("Точность модели на тестовых данных: %.2f%%" % (scores[1]*100))
