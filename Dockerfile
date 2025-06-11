# Usar uma imagem base do Python
FROM python:3.9-slim

# Copiar o código Python para o contêiner
COPY app.py /app.py

# Executar o código Python
CMD ["python", "/app.py"]