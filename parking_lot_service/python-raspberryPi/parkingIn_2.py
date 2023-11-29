# pip install pytesseract

from PIL import Image
import pytesseract

pytesseract.pytesseract.tesseract_cmd = r'D:\Program Files\Tesseract-OCR\tesseract.exe'
text = pytesseract.image_to_string(Image.open(r"C:\Users\mnnnd\OneDrive\바탕 화면\parking_lot_service\python-raspberryPi\aa.png"), lang="kor")
print(text)
# print(text.replace(" ", ""))

with open("news.txt", "w", encoding="utf8") as f:
    f.write(text)