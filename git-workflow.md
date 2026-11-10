# Worflow Básico do Git 
Guia rápido com comandos essenciais para colaborar no repositório

## 1. Clonar o Repositório

Baixe o projeto para a sua máquina:

```bash
git clone https://github.com/palaioz/Manipulacao-de-Matrizes.git
cd caminho/para/a/pasta/Manipulacao-de-Matrizes
```

## 2. Ciclo Diário

Sempre que fizer alterações no código:

```bash 
git add . # Adicionar arquivos modificados 
git commit -m "Descreva o que você fez aqui brevemente" # Salvar as alterações 
git push origin main # Enviar para o repositório remoto 
```

## 3. Atualizar o Projeto 

Antes de começar a trabalhar (ou antes de dar o ```push```), baixe as atualizações dos seus colegas: 

```bash
git pull origin main 
```

## 4. Fetch e Merge (alternativa ao pull)

Se quiser ver o que mudou antes de juntar com o seu código:

```bash 
git fetch # Baixar as novidades sem aplicar 
git merge # Juntar as alterações com o seu branch atual 
```

## 5. Resolvendo Conflitos 

Se você e um colega alterarem exatamente a mesma linha do mesmo arquivo, o Git vai pausar e avisar sobre um conflito.

1. Abra o arquivo no seu editor (VS Code, DevC++, CodeBlocks, etc.);
2. O Git marcará a área do conflito com símbolos como ```<<<<<<```, ```======``` e ```>>>>>>```;
3. Apague os símbolos e decida qual código deve ficar; 
4. Salve o arquivo e finalize o processo:
```bash 
git add <arquivo-modificado> # ou git add .
git commit -m "Resolve conflito"
git push origin main # só git push também funciona
```


