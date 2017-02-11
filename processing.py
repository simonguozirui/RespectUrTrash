#
# Pip install the client:
# pip install clarifai
#

# The package will be accessible by importing clarifai:

from clarifai import rest
from clarifai.rest import ClarifaiApp

# The client takes the `APP_ID` and `APP_SECRET` you created in your <a href="/account/application">Clarifai
# account.</a> You can set these variables in your environment as:

# - `CLARIFAI_APP_ID`
# - `CLARIFAI_APP_SECRET`


app = ClarifaiApp("4dR2VJxpC1r5oHSwjk_0XnQXK7k5jEv6tRcuDVb9", "6o187-_f803bdezLfDCZNj5mKqf9_LAKFq95UACD")

# get the general model
model = app.models.get("aaa03c23b3724a16a56b629203edc62c")

# predict with the model
print(model.predict_by_url(url='https://samples.clarifai.com/metro-north.jpg'))