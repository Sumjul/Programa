# Efektyvumo Tyrimai (v1.0)

Šiame skyriuje pateikiami išsamūs našumo testų rezultatai, susiję su duomenų failų nuskaitymu, rūšiavimu ir skyrstymu į dvį grupes priklausomai nuo naudojamo konteinerio tipo.
Nuo 5 punkto aprašyti Studentų rūšiavimo (dalijimo) į dvi kategorijas optimizavimo testų rezultatai.

- **CPU:** i7-12700H; 2.70 GHz
- **RAM:** SODIMM; 16,0 GB
- **SSD:** Micron_2450; 954 GB

## 1. Duomenų nuskaitymas iš failų į atitinkamą konteinerį

### 1.1. std::vector

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0065674        |
| `st10000.txt`    | 0.0602441        |
| `st100000.txt`   | 0.617428         |
| `st1000000.txt`  | 4.29796          |
| `st10000000.txt` | 138.158          |

### 1.2. std::deque

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0081942        |
| `st10000.txt`    | 0.0656441        |
| `st100000.txt`   | 0.650874         |
| `st1000000.txt`  | 4.69346          |
| `st10000000.txt` | 182.16           |

### 1.3. std::list

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0074983        |
| `st10000.txt`    | 0.0648295        |
| `st100000.txt`   | 0.696449         |
| `st1000000.txt`  | 5.86576          |
| `st10000000.txt` | 198.764          |

## 2. Studentų rūšiavimas didėjimo tvarką konteineryje

### 2.1. std::vector

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0001239        |
| `st10000.txt`    | 0.0009806        |
| `st100000.txt`   | 0.0113056        |
| `st1000000.txt`  | 0.147859         |
| `st10000000.txt` | 1.67796          |

### 2.2. std::deque

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0001762        |
| `st10000.txt`    | 0.0017455        |
| `st100000.txt`   | 0.0169953        |
| `st1000000.txt`  | 0.263941         |
| `st10000000.txt` | 3.38628          |

### 2.3. std::list

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0001496        |
| `st10000.txt`    | 0.001762         |
| `st100000.txt`   | 0.0978846        |
| `st1000000.txt`  | 0.675113         |
| `st10000000.txt` | 10.812           |

## 3. Studentų skirstymas į dvi grupes/kategorijas

### 3.1. std::vector

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0030289        |
| `st10000.txt`    | 0.164812         |
| `st100000.txt`   | 1.16997          |
| `st1000000.txt`  | 2.00772          |
| `st10000000.txt` | 11.0071          |

### 3.2. std::deque

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0011855        |
| `st10000.txt`    | 0.0070657        |
| `st100000.txt`   | 0.0772563        |
| `st1000000.txt`  | 1.05031          |
| `st10000000.txt` | 10.4359          |

### 3.3. std::list

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0018212        |
| `st10000.txt`    | 0.0095576        |
| `st100000.txt`   | 0.0978846        |
| `st1000000.txt`  | 0.888093         |
| `st10000000.txt` | 14.093           |

## 4. Išvados

- **std::vector** yra optimalesnis pasirinkimas tiek duomenų nuskaitymui, tiek rūšiavimui, tiek skirstymui į grupes, ypač didesniuose failuose.

- **std::deque** ir **std::list** gali būti tinkami mažesniems duomenims, tačiau su didesniais failais jų našumas gerokai prastesnis.

---

## 5. Bendro studentai konteinerio skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius

### 5.1. std::vector

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0030289        |
| `st10000.txt`    | 0.164812         |
| `st100000.txt`   | 1.16997          |
| `st1000000.txt`  | 2.00772          |
| `st10000000.txt` | 11.0071          |

### 5.2. std::deque

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0011855        |
| `st10000.txt`    | 0.0070657        |
| `st100000.txt`   | 0.0772563        |
| `st1000000.txt`  | 1.05031          |
| `st10000000.txt` | 10.4359          |

### 5.3. std::list

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     | 0.0018212        |
| `st10000.txt`    | 0.0095576        |
| `st100000.txt`   | 0.0978846        |
| `st1000000.txt`  | 0.888093         |
| `st10000000.txt` | 14.093           |

## 6. Bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai"

### 6.1. std::vector

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     |         |
| `st10000.txt`    |          |
| `st100000.txt`   |           |
| `st1000000.txt`  |           |
| `st10000000.txt` |           |

### 6.2. std::deque

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     |         |
| `st10000.txt`    |         |
| `st100000.txt`   |         |
| `st1000000.txt`  |           |
| `st10000000.txt` |           |

### 6.3. std::list

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     |         |
| `st10000.txt`    |         |
| `st100000.txt`   |         |
| `st1000000.txt`  |          |
| `st10000000.txt` |            |

## 7. Bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant greičiausiai veikianti 1 arba 2 strategiją  įtraukiant į ją "efektyvius" darbo su konteineriais metodus

### 7.1. std::vector

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     |         |
| `st10000.txt`    |          |
| `st100000.txt`   |           |
| `st1000000.txt`  |           |
| `st10000000.txt` |           |

### 7.2. std::deque

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     |         |
| `st10000.txt`    |         |
| `st100000.txt`   |         |
| `st1000000.txt`  |           |
| `st10000000.txt` |           |

### 7.3. std::list

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st1000.txt`     |         |
| `st10000.txt`    |         |
| `st100000.txt`   |         |
| `st1000000.txt`  |          |
| `st10000000.txt` |            |

## 8. Išvados
