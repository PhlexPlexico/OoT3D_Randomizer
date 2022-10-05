#include "item_list.hpp"

#include "logic.hpp"
#include "../code/include/z3D/z3Ditem.h"
#include <array>

using namespace Logic;

static std::array<Item, KEY_ENUM_MAX> itemTable;

void ItemTable_Init() { // Item Type                   getItemID             advancement  logic hint key English name
                        // French                              Spanish                                     Italian
                        // German
    itemTable[NONE] = Item(ITEMTYPE_EVENT, GI_RUPEE_GREEN, false, &noVariable, NONE,
                           Text{ "No Item", "Rien", "Sin Objeto", "Nessun Oggetto", "Deutsch" });
    itemTable[KOKIRI_SWORD] =
        Item(ITEMTYPE_ITEM, GI_SWORD_KOKIRI, true, &KokiriSword, KOKIRI_SWORD,
             Text{ "Kokiri Sword", "Épée Kokiri", "Espada Kokiri", "Spada dei Kokiri", "Kokiri-Schwert" });
    itemTable[MASTER_SWORD] =
        Item(ITEMTYPE_ITEM, GI_SWORD_MASTER, true, &MasterSword, MASTER_SWORD,
             Text{ "Master Sword", "Épée de légende", "Espada Maestra", "Spada suprema", "Master-Schwert" });
    itemTable[GIANTS_KNIFE] =
        Item(ITEMTYPE_ITEM, GI_SWORD_KNIFE, false, &noVariable, GIANTS_KNIFE,
             Text{ "Giant's Knife", "Lame de géant", "Daga gigante", "Spada del gigante", "Langschwert" });
    itemTable[BIGGORON_SWORD] = Item(ITEMTYPE_ITEM, GI_SWORD_BGS, true, &BiggoronSword, BIGGORON_SWORD,
                                     Text{ "Biggoron's Sword", "Épée de Grogoron", "Espada de Biggoron",
                                           "Spada di Grande Goron", "Biggoron-Schwert" });
    itemTable[DEKU_SHIELD] = Item(ITEMTYPE_ITEM, GI_SHIELD_DEKU, false, &noVariable, DEKU_SHIELD,
                                  Text{ "Deku Shield", "Bouclier Mojo", "Escudo deku", "Scudo Deku", "Deku-Schild" });
    itemTable[HYLIAN_SHIELD] =
        Item(ITEMTYPE_ITEM, GI_SHIELD_HYLIAN, false, &noVariable, HYLIAN_SHIELD,
             Text{ "Hylian Shield", "Bouclier Hylien", "Escudo hyliano", "Scudo Hylia", "Hylia-Schild" });
    itemTable[MIRROR_SHIELD] =
        Item(ITEMTYPE_ITEM, GI_SHIELD_MIRROR, true, &MirrorShield, MIRROR_SHIELD,
             Text{ "Mirror Shield", "Bouclier miroir", "Escudo espejo", "Scudo specchio", "Spiegel-Schild" });
    itemTable[GORON_TUNIC] = Item(ITEMTYPE_ITEM, GI_TUNIC_GORON, true, &GoronTunic, GORON_TUNIC,
                                  Text{ "Goron Tunic", "Tunique Goron", "Sayo goron", "Veste dei Goron", "Deutsch" });
    itemTable[ZORA_TUNIC] = Item(ITEMTYPE_ITEM, GI_TUNIC_ZORA, true, &ZoraTunic, ZORA_TUNIC,
                                 Text{ "Zora Tunic", "Tunique Zora", "Sayo zora", "Veste degli Zora", "Deutsch" });
    itemTable[IRON_BOOTS] =
        Item(ITEMTYPE_ITEM, GI_BOOTS_IRON, true, &IronBoots, IRON_BOOTS,
             Text{ "Iron Boots", "Bottes de plomb", "Botas de hierro", "Stivali di ferro", "Eisenstiefel" });
    itemTable[HOVER_BOOTS] =
        Item(ITEMTYPE_ITEM, GI_BOOTS_HOVER, true, &HoverBoots, HOVER_BOOTS,
             Text{ "Hover Boots", "Bottes des airs", "Botas voladoras", "Stivali alati", "Gleitstiefel" });

    itemTable[BOOMERANG] = Item(ITEMTYPE_ITEM, GI_BOOMERANG, true, &Boomerang, BOOMERANG,
                                Text{ "Boomerang", "Boomerang", "Búmeran", "Boomerang", "Bumerang" });
    itemTable[LENS_OF_TRUTH] = Item(
        ITEMTYPE_ITEM, GI_LENS, true, &LensOfTruth, LENS_OF_TRUTH,
        Text{ "Lens of Truth", "Loupe de vérité", "Lupa de la Verdad", "Lente della verità", "Auge der Wahrheit" });
    itemTable[MEGATON_HAMMER] =
        Item(ITEMTYPE_ITEM, GI_HAMMER, true, &Hammer, MEGATON_HAMMER,
             Text{ "Megaton Hammer", "Masse des titans", "Martillo Megatón", "Martello megaton", "Stahlhammer" });
    itemTable[SHARD_OF_AGONY] = Item(ITEMTYPE_ITEM, GI_STONE_OF_AGONY, true, &ShardOfAgony, SHARD_OF_AGONY,
                                     Text{ "Shard of Agony", "Fragment de souffrance", "Piedra de la Agonía",
                                           "Cristallo sonoro", "Stein des Wissens" });
    itemTable[DINS_FIRE] =
        Item(ITEMTYPE_ITEM, GI_DINS_FIRE, true, &DinsFire, DINS_FIRE,
             Text{ "Din's Fire", "Feu de Din", "Fuego de Din", "Fuoco di Din", "Dins Feuerinferno" });
    itemTable[FARORES_WIND] =
        Item(ITEMTYPE_ITEM, GI_FARORES_WIND, true, &FaroresWind, FARORES_WIND,
             Text{ "Farore's Wind", "Vent de Farore", "Viento de Farore", "Vento di Farore", "Farores Donnersturm" });
    itemTable[NAYRUS_LOVE] =
        Item(ITEMTYPE_ITEM, GI_NAYRUS_LOVE, true, &NayrusLove, NAYRUS_LOVE,
             Text{ "Nayru's Love", "Amour de Nayru", "Amor de Nayru", "Amore di Nayru", "Nayrus Umarmung" });
    itemTable[FIRE_ARROWS] =
        Item(ITEMTYPE_ITEM, GI_ARROW_FIRE, true, &FireArrows, FIRE_ARROWS,
             Text{ "Fire Arrow", "Flèche de feu", "Flecha de fuego", "Freccia di fuoco", "Feuer-Pfeile" });
    itemTable[ICE_ARROWS] =
        Item(ITEMTYPE_ITEM, GI_ARROW_ICE, true, &IceArrows, ICE_ARROWS,
             Text{ "Ice Arrow", "Flèche de glace", "Flecha de hielo", "Freccia di ghiaccio", "Eis-Pfeile" });
    itemTable[LIGHT_ARROWS] =
        Item(ITEMTYPE_ITEM, GI_ARROW_LIGHT, true, &LightArrows, LIGHT_ARROWS,
             Text{ "Light Arrow", "Flèche de lumière", "Flecha de luz", "Freccia di luce", "Pfeile des Lichts" });
    itemTable[GERUDO_TOKEN] =
        Item(ITEMTYPE_ITEM, GI_GERUDO_CARD, true, &GerudoToken, GERUDO_TOKEN,
             Text{ "Gerudo Token", "Carte Gerudo", "Pase de socio gerudo", "Gerudo Card", "Gerudo-Pass" });
    itemTable[MAGIC_BEAN] =
        Item(ITEMTYPE_ITEM, GI_BEAN, true, &MagicBean, MAGIC_BEAN,
             Text{ "Magic Bean", "Haricot magique", "Habichuelas mágicas", "Fagioli magici", "Wundererbse" });
    itemTable[MAGIC_BEAN_PACK] = Item(ITEMTYPE_ITEM, 0xC9, true, &MagicBeanPack, MAGIC_BEAN_PACK,
                                      Text{ "Magic Bean Pack", "Paquet de haricots magiques",
                                            "Lote de habichuelas mágicas", "Pacco di fagioli magici", "Deutsch" });
    itemTable[DOUBLE_DEFENSE] =
        Item(ITEMTYPE_ITEM, 0xB8, true, &DoubleDefense, DOUBLE_DEFENSE,
             Text{ "Double Defense", "Double défence", "Doble poder defensivo", "Doppia difesa", "Deutsch" });

    itemTable[WEIRD_EGG] = Item(ITEMTYPE_ITEM, GI_WEIRD_EGG, true, &WeirdEgg, WEIRD_EGG,
                                Text{ "Weird Egg", "Œuf curieux", "Huevo extraño", "Uovo misterioso", "Seltsames Ei" });
    //  itemTable[CUCCO]                             = Item(ITEMTYPE_ITEM,              GI_CUCCO,             true,
    //  &Cucco,                     CUCCO,                             Text{"Cucco", "Cocotte", "Cuco", "Coccò",
    //  "Huhn"});
    itemTable[ZELDAS_LETTER] =
        Item(ITEMTYPE_ITEM, GI_LETTER_ZELDA, true, &ZeldasLetter, ZELDAS_LETTER,
             Text{ "Zelda's Letter", "Lettre de Zelda", "Carta de Zelda", "Lettera di Zelda", "Zeldas Brief" });
    //  itemTable[KEATON_MASK]                       = Item(ITEMTYPE_ITEM,              GI_MASK_KEATON,       true,
    //  &KeatonMask,                KEATON_MASK,                       Text{"Keaton Mask",                     "Masque
    //  de Keaton",                 "Máscara de Keaton",                        "Maschera Keaton", "Fuchs-Maske"});
    //  itemTable[SKULL_MASK]                        = Item(ITEMTYPE_ITEM,              GI_MASK_SKULL,        true,
    //  &SkullMask,                 SKULL_MASK,                        Text{"Skull Mask",                      "Masque
    //  de mort",                   "Máscara de calavera",                      "Maschera Teschio", "Deutsch"});
    //  itemTable[SPOOKY_MASK]                       = Item(ITEMTYPE_ITEM,              GI_MASK_SPOOKY,       true,
    //  &SpookyMask,                SPOOKY_MASK,                       Text{"Spooky Mask",                     "Masque
    //  d'Effroi",                  "Máscara tenebrosa",                        "Maschera spaventosa",
    //  "Geister-Maske"}); itemTable[BUNNY_HOOD]                        = Item(ITEMTYPE_ITEM, GI_MASK_BUNNY, true,
    //  &BunnyHood,                 BUNNY_HOOD,                        Text{"Bunny Hood",                      "Masque
    //  du lapin",                  "Capucha de conejo",                        "Orecchie da coniglio", "Hasenohren"});
    //  itemTable[GORON_MASK]                        = Item(ITEMTYPE_ITEM,              GI_MASK_GORON,        true,
    //  &GoronMask,                 GORON_MASK,                        Text{"Goron Mask",                      "Masque
    //  Goron",                     "Máscara Goron",                            "Maschera Goron", "Goronen-Maske"});
    //  itemTable[ZORA_MASK]                         = Item(ITEMTYPE_ITEM,              GI_MASK_ZORA,         true,
    //  &ZoraMask,                  ZORA_MASK,                         Text{"Zora Mask",                       "Masque
    //  Zora",                      "Máscara Zora",                             "Maschera Zora", "Zora-Maske"});
    //  itemTable[GERUDO_MASK]                       = Item(ITEMTYPE_ITEM,              GI_MASK_GERUDO,       true,
    //  &GerudoMask,                GERUDO_MASK,                       Text{"Gerudo Mask",                     "Masque
    //  Gerudo",                    "Máscara Gerudo",                           "Maschera Gerudo", "Gerudo-Maske"});
    //  itemTable[MASK_OF_TRUTH]                     = Item(ITEMTYPE_ITEM,              GI_MASK_MASK,         true,
    //  &MaskofTruth,               MASK_OF_TRUTH,                     Text{"Mask of Truth",                   "Masque
    //  de vérité",                 "Máscara de la Verdad",                     "Maschera della verità", "Maske des
    //  Wissens"});
    itemTable[POCKET_EGG] = Item(ITEMTYPE_ITEM, GI_POCKET_EGG, true, &PocketEgg, POCKET_EGG,
                                 Text{ "Pocket Egg", "Œuf de poche", "Huevo de bolsillo", "Uovo tascabile", "Ei" });
    //  itemTable[POCKET_CUCCO]                      = Item(ITEMTYPE_ITEM,              GI_POCKET_CUCCO,      true,
    //  &PocketCucco,               POCKET_CUCCO,                      Text{"Pocket Cucco",                    "Cocotte
    //  de poche",                 "Cuco de bolsillo",                         "Coccò tascabile", "Kiki"});
    itemTable[COJIRO] = Item(ITEMTYPE_ITEM, GI_COJIRO, true, &Cojiro, COJIRO,
                             Text{ "Cojiro", "P'tit Poulet", "Cojiro", "Coblù", "Henni" });
    itemTable[ODD_MUSHROOM] =
        Item(ITEMTYPE_ITEM, GI_ODD_MUSHROOM, true, &OddMushroom, ODD_MUSHROOM,
             Text{ "Odd Mushroom", "Champignon suspect", "Champiñón extraño", "Fungo strano", "Schimmelpilz" });
    itemTable[ODD_POULTICE] =
        Item(ITEMTYPE_ITEM, GI_ODD_POTION, true, &OddPoultice, ODD_POULTICE,
             Text{ "Odd Poultice", "Mixture suspecte", "Medicina rara", "Medicina strana", "Moderpackung" });
    itemTable[POACHERS_SAW] =
        Item(ITEMTYPE_ITEM, GI_SAW, true, &PoachersSaw, POACHERS_SAW,
             Text{ "Poacher's Saw", "Scie du chasseur", "Sierra del furtivo", "Sega del bracconiere", "Deutsch" });
    itemTable[BROKEN_SWORD] = Item(ITEMTYPE_ITEM, GI_SWORD_BROKEN, true, &BrokenSword, BROKEN_SWORD,
                                   Text{ "Broken Goron's Sword", "Épée brisée de Goron", "Espada goron rota",
                                         "Spada rotta dei Goron", "Zerbrochenes Goronen-Schwert" });
    itemTable[PRESCRIPTION] = Item(ITEMTYPE_ITEM, GI_PERSCRIPTION, true, &Prescription, PRESCRIPTION,
                                   Text{ "Prescription", "Ordonnance", "Receta", "Ricetta", "Rezept" });
    itemTable[EYEBALL_FROG] =
        Item(ITEMTYPE_ITEM, GI_FROG, true, &EyeballFrog, EYEBALL_FROG,
             Text{ "Eyeball Frog", "Crapaud-qui-louche", "Rana de ojos saltones", "Rana occhiuta", "Glotzfrosch" });
    itemTable[EYEDROPS] = Item(ITEMTYPE_ITEM, GI_EYEDROPS, true, &Eyedrops, EYEDROPS,
                               Text{ "World's Finest Eyedrops", "Super gouttes", "Supergotas oculares",
                                     "Miglior collirio del mondo", "Augentropfen" });
    itemTable[CLAIM_CHECK] = Item(ITEMTYPE_ITEM, GI_CLAIM_CHECK, true, &ClaimCheck, CLAIM_CHECK,
                                  Text{ "Claim Check", "Certificat", "Recibo", "Buono", "Zertifikat" });

    itemTable[GOLD_SKULLTULA_TOKEN] =
        Item(ITEMTYPE_TOKEN, GI_SKULL_TOKEN, true, &GoldSkulltulaTokens, GOLD_SKULLTULA_TOKEN,
             Text{ "Gold Skulltula Token", "Jeton de Skulltula dorée", "Símbolo de skulltula dorada", "Teschio d'oro",
                   "Goldene Skulltula" });

    // Progression Items
    itemTable[PROGRESSIVE_HOOKSHOT] =
        Item(ITEMTYPE_ITEM, 0x80, true, &ProgressiveHookshot, PROGRESSIVE_HOOKSHOT,
             Text{ "Progressive Hookshot", "Grappin (prog.)", "Gancho progresivo", "Arpione progressivo", "Deutsch" });
    itemTable[PROGRESSIVE_STRENGTH] =
        Item(ITEMTYPE_ITEM, 0x81, true, &ProgressiveStrength, PROGRESSIVE_STRENGTH,
             Text{ "Progressive Strength Upgrade", "Amélioration de force (prog.)", "Fuerza progresiva",
                   "Potenziamento di forza progressivo", "Deutsch" });
    itemTable[PROGRESSIVE_BOMB_BAG] = Item(ITEMTYPE_ITEM, 0x82, true, &ProgressiveBombBag, PROGRESSIVE_BOMB_BAG,
                                           Text{ "Progressive Bomb Bag", "Sac de bombes (prog.)",
                                                 "Saco de bombas progresivo", "Portabombe progressivo", "Deutsch" });
    itemTable[PROGRESSIVE_BOW] =
        Item(ITEMTYPE_ITEM, 0x83, true, &ProgressiveBow, PROGRESSIVE_BOW,
             Text{ "Progressive Bow", "Arc (prog.)", "Arco progresivo", "Arco progressivo", "Deutsch" });
    itemTable[PROGRESSIVE_SLINGSHOT] = Item(ITEMTYPE_ITEM, 0x84, true, &ProgressiveBulletBag, PROGRESSIVE_SLINGSHOT,
                                            Text{ "Progressive Slingshot", "Lance-pierre (prog.)",
                                                  "Resortera progresiva", "Fionda progressiva", "Deutsch" });
    itemTable[PROGRESSIVE_WALLET] = Item(ITEMTYPE_ITEM, 0x85, true, &ProgressiveWallet, PROGRESSIVE_WALLET,
                                         Text{ "Progressive Wallet", "Bourse (prog.)", "Bolsa de rupias progresiva",
                                               "Portarupie progressivo", "Deutsch" });
    itemTable[PROGRESSIVE_SCALE] =
        Item(ITEMTYPE_ITEM, 0x86, true, &ProgressiveScale, PROGRESSIVE_SCALE,
             Text{ "Progressive Scale", "Écaille (prog.)", "Escama progresiva", "Squama progressiva", "Deutsch" });
    itemTable[PROGRESSIVE_NUT_UPGRADE] =
        Item(ITEMTYPE_ITEM, 0x87, false, &noVariable, PROGRESSIVE_NUT_UPGRADE,
             Text{ "Progressive Nut Capacity", "Capacité de noix (prog.)", "Capacidad de nueces deku progresiva",
                   "Capacità di noci Deku progressiva", "Deutsch" });
    itemTable[PROGRESSIVE_STICK_UPGRADE] =
        Item(ITEMTYPE_ITEM, 0x88, false, &noVariable, PROGRESSIVE_STICK_UPGRADE,
             Text{ "Progressive Stick Capacity", "Capacité de bâtons (prog.)", "Capacidad de palos deku progresiva",
                   "Capacità di rami Deku progressiva", "Deutsch" });
    itemTable[PROGRESSIVE_BOMBCHUS] = Item(
        ITEMTYPE_ITEM, 0x89, true, &Bombchus, PROGRESSIVE_BOMBCHUS,
        Text{ "Progressive Bombchu", "Bombchus (prog.)", "Bombchus progresivos", "Radiomine progressive", "Deutsch" });
    itemTable[PROGRESSIVE_MAGIC_METER] =
        Item(ITEMTYPE_ITEM, 0x8A, true, &ProgressiveMagic, PROGRESSIVE_MAGIC_METER,
             Text{ "Progressive Magic Meter", "Jauge de magie (prog.)", "Poder mágico progresivo",
                   "Barra della magia progressiva", "Deutsch" });
    itemTable[PROGRESSIVE_OCARINA] =
        Item(ITEMTYPE_ITEM, 0x8B, true, &ProgressiveOcarina, PROGRESSIVE_OCARINA,
             Text{ "Progressive Ocarina", "Ocarina (prog.)", "Ocarina progresiva", "Ocarina progressiva", "Deutsch" });
    itemTable[PROGRESSIVE_GORONSWORD] = Item(ITEMTYPE_ITEM, 0xD4, true, &ProgressiveGiantKnife, PROGRESSIVE_GORONSWORD,
                                             Text{ "Progressive Goron Sword", "Épée Goron (prog.)",
                                                   "Espada Goron progresiva", "Spada Goron progressiva", "Deutsch" });

    // Bottles
    itemTable[EMPTY_BOTTLE] = Item(ITEMTYPE_ITEM, 0x0F, true, &Bottles, EMPTY_BOTTLE,
                                   Text{ "Empty Bottle", "Flacon vide", "Botella vacía", "Ampolla", "Deutsch" });
    itemTable[BOTTLE_WITH_RED_POTION] = Item(ITEMTYPE_ITEM, 0x8C, true, &Bottles, BOTTLE_WITH_RED_POTION,
                                             Text{ "Bottle with Red Potion", "Flacon de potion rouge",
                                                   "Botella de poción roja", "Ampolla di pozione vita", "Deutsch" });
    itemTable[BOTTLE_WITH_MILK] = Item(ITEMTYPE_ITEM, 0x14, true, &Bottles, BOTTLE_WITH_MILK,
                                       Text{ "Bottle with Milk", "Flacon de lait", "Botella de leche Lon Lon",
                                             "Ampolla di latte Lon Lon", "Deutsch" });
    itemTable[BOTTLE_WITH_GREEN_POTION] =
        Item(ITEMTYPE_ITEM, 0x8D, true, &Bottles, BOTTLE_WITH_GREEN_POTION,
             Text{ "Bottle with Green Potion", "Flacon de potion verte", "Botella de poción verde",
                   "Ampolla di pozione magica", "Deutsch" });
    itemTable[BOTTLE_WITH_BLUE_POTION] =
        Item(ITEMTYPE_ITEM, 0x8E, true, &Bottles, BOTTLE_WITH_BLUE_POTION,
             Text{ "Bottle with Blue Potion", "Flacon de potion bleue", "Botella de poción azul",
                   "Ampolla di pozione curatutto", "Deutsch" });
    itemTable[BOTTLE_WITH_FAIRY] = Item(
        ITEMTYPE_ITEM, 0x8F, true, &Bottles, BOTTLE_WITH_FAIRY,
        Text{ "Bottle with Fairy", "Flacon avec une fée", "Hada en una botella", "Fata in un'ampolla", "Deutsch" });
    itemTable[BOTTLE_WITH_FISH] = Item(
        ITEMTYPE_ITEM, 0x90, true, &Bottles, BOTTLE_WITH_FISH,
        Text{ "Bottle with Fish", "Flacon avec un poisson", "Pez en una botella", "Pesce in un'ampolla", "Deutsch" });
    itemTable[BOTTLE_WITH_BLUE_FIRE] = Item(ITEMTYPE_ITEM, 0x91, true, &Bottles, BOTTLE_WITH_BLUE_FIRE,
                                            Text{ "Bottle with Blue Fire", "Flacon de flamme bleue",
                                                  "Botella de fuego azul", "Ampolla di fuoco blu", "Deutsch" });
    itemTable[BOTTLE_WITH_BUGS] = Item(
        ITEMTYPE_ITEM, 0x92, true, &Bottles, BOTTLE_WITH_BUGS,
        Text{ "Bottle with Bugs", "Flacon d'insectes", "Insecto en una botella", "Insetto in un'ampolla", "Deutsch" });
    itemTable[BOTTLE_WITH_POE] =
        Item(ITEMTYPE_ITEM, 0x94, true, &Bottles, BOTTLE_WITH_POE,
             Text{ "Bottle with Poe", "Flacon avec un Esprit", "Poe en una botella", "Poo in un'ampolla", "Deutsch" });

    // Special bottles that can't immediately dump contents
    itemTable[RUTOS_LETTER] = Item(ITEMTYPE_ITEM, 0x15, true, &RutosLetter, RUTOS_LETTER,
                                   Text{ "Bottle with Ruto's Letter", "Flacon avec une lettre", "Carta de Ruto",
                                         "Lettera in un'ampolla", "Deutsch" });
    itemTable[BOTTLE_WITH_BIG_POE] = Item(ITEMTYPE_ITEM, 0x93, true, &BottleWithBigPoe, BOTTLE_WITH_BIG_POE,
                                          Text{ "Bottle with Big Poe", "Flacon avec une Âme", "Gran Poe en una botella",
                                                "Grande Poo in un'ampolla", "Deutsch" });

    // Songs
    itemTable[ZELDAS_LULLABY] = Item(
        ITEMTYPE_SONG, 0xC1, true, &ZeldasLullaby, ZELDAS_LULLABY,
        Text{ "Zelda's Lullaby", "Berceuse de Zelda", "Nana de Zelda", "Ninna nanna di Zelda", "Zeldas Wiegenlied" });
    itemTable[EPONAS_SONG] =
        Item(ITEMTYPE_SONG, 0xC2, true, &EponasSong, EPONAS_SONG,
             Text{ "Epona's Song", "Chant d'Épona", "Canción de Epona", "Canzone di Epona", "Eponas Lied" });
    itemTable[SARIAS_SONG] =
        Item(ITEMTYPE_SONG, 0xC3, true, &SariasSong, SARIAS_SONG,
             Text{ "Saria's Song", "Chant de Saria", "Canción de Saria", "Canzone di Saria", "Salias Lied" });
    itemTable[SUNS_SONG] =
        Item(ITEMTYPE_SONG, 0xC4, true, &SunsSong, SUNS_SONG,
             Text{ "Sun's Song", "Chant du soleil", "Canción del Sol", "Canto del sole", "Hymne der Sonne" });
    itemTable[SONG_OF_TIME] =
        Item(ITEMTYPE_SONG, 0xC5, true, &SongOfTime, SONG_OF_TIME,
             Text{ "Song of Time", "Chant du temps", "Canción del tiempo", "Canzone del tempo", "Hymne der Zeit" });
    itemTable[SONG_OF_STORMS] = Item(ITEMTYPE_SONG, 0xC6, true, &SongOfStorms, SONG_OF_STORMS,
                                     Text{ "Song of Storms", "Chant des tempêtes", "Canción de la tormenta",
                                           "Canzone della tempesta", "Hymne des Sturms" });
    itemTable[MINUET_OF_FOREST] = Item(ITEMTYPE_SONG, 0xBB, true, &MinuetOfForest, MINUET_OF_FOREST,
                                       Text{ "Minuet of Forest", "Menuet de la forêt", "Minueto del bosque",
                                             "Minuetto della foresta", "Menuett des Waldes" });
    itemTable[BOLERO_OF_FIRE] =
        Item(ITEMTYPE_SONG, 0xBC, true, &BoleroOfFire, BOLERO_OF_FIRE,
             Text{ "Bolero of Fire", "Boléro du feu", "Bolero del fuego", "Bolero del fuoco", "Bolero des Feuers" });
    itemTable[SERENADE_OF_WATER] = Item(ITEMTYPE_SONG, 0xBD, true, &SerenadeOfWater, SERENADE_OF_WATER,
                                        Text{ "Serenade of Water", "Sérénade de l'eau", "Serenata del agua",
                                              "Serenata dell'acqua", "Serenade des Wassers" });
    itemTable[REQUIEM_OF_SPIRIT] = Item(ITEMTYPE_SONG, 0xBE, true, &RequiemOfSpirit, REQUIEM_OF_SPIRIT,
                                        Text{ "Requiem of Spirit", "Requiem des esprits", "Réquiem del espíritu",
                                              "Requiem dello spirito", "Requiem der Geister" });
    itemTable[NOCTURNE_OF_SHADOW] = Item(ITEMTYPE_SONG, 0xBF, true, &NocturneOfShadow, NOCTURNE_OF_SHADOW,
                                         Text{ "Nocturne of Shadow", "Nocturne de l'ombre", "Nocturno de la sombra",
                                               "Notturno delle ombre", "Nocturne des Schattens" });
    itemTable[PRELUDE_OF_LIGHT] = Item(ITEMTYPE_SONG, 0xC0, true, &PreludeOfLight, PRELUDE_OF_LIGHT,
                                       Text{ "Prelude of Light", "Prélude de la lumière", "Preludio de la luz",
                                             "Preludio della luce", "Kantate des Lichts" });

    // Maps and Compasses
    itemTable[DEKU_TREE_MAP] = Item(ITEMTYPE_MAP, 0xA5, false, &noVariable, DEKU_TREE_MAP,
                                    Text{ "Great Deku Tree Map", "Carte de l'arbre Mojo", "Mapa del Gran Árbol Deku",
                                          "Mappa del Grande Albero Deku", "Deutsch" });
    itemTable[DODONGOS_CAVERN_MAP] =
        Item(ITEMTYPE_MAP, 0xA6, false, &noVariable, DODONGOS_CAVERN_MAP,
             Text{ "Dodongo's Cavern Map", "Carte de la grotte Dodongo", "Mapa de la Cueva de los Dodongos",
                   "Mappa della caverna dei Dodongo", "Deutsch" });
    itemTable[JABU_JABUS_BELLY_MAP] =
        Item(ITEMTYPE_MAP, 0xA7, false, &noVariable, JABU_JABUS_BELLY_MAP,
             Text{ "Jabu-Jabu's Belly Map", "Carte de Jabu-Jabu", "Mapa de la tripa de Jabu-Jabu",
                   "Mappa della pancia di Jabu Jabu", "Deutsch" });
    itemTable[FOREST_TEMPLE_MAP] =
        Item(ITEMTYPE_MAP, 0xA8, false, &noVariable, FOREST_TEMPLE_MAP,
             Text{ "Forest Temple Map", "Carte du temple de la forêt", "Mapa del Templo del Bosque",
                   "Mappa del Santuario della Foresta", "Deutsch" });
    itemTable[FIRE_TEMPLE_MAP] = Item(ITEMTYPE_MAP, 0xA9, false, &noVariable, FIRE_TEMPLE_MAP,
                                      Text{ "Fire Temple Map", "Carte du temple du feu", "Mapa del Templo del Fuego",
                                            "Mappa del Santuario del Fuoco", "Deutsch" });
    itemTable[WATER_TEMPLE_MAP] = Item(ITEMTYPE_MAP, 0xAA, false, &noVariable, WATER_TEMPLE_MAP,
                                       Text{ "Water Temple Map", "Carte du temple de l'eau", "Mapa del Templo del Agua",
                                             "Mappa del Santuario dell'Acqua", "Deutsch" });
    itemTable[SPIRIT_TEMPLE_MAP] =
        Item(ITEMTYPE_MAP, 0xAB, false, &noVariable, SPIRIT_TEMPLE_MAP,
             Text{ "Spirit Temple Map", "Carte du temple de l'esprit", "Mapa del Templo del Espíritu",
                   "Mappa del Santuario dello Spirito", "Deutsch" });
    itemTable[SHADOW_TEMPLE_MAP] =
        Item(ITEMTYPE_MAP, 0xAC, false, &noVariable, SHADOW_TEMPLE_MAP,
             Text{ "Shadow Temple Map", "Carte du temple de l'ombre", "Mapa del Templo de la Sombra",
                   "Mappa del Santuario dell'Ombra", "Deutsch" });
    itemTable[BOTTOM_OF_THE_WELL_MAP] = Item(ITEMTYPE_MAP, 0xAD, false, &noVariable, BOTTOM_OF_THE_WELL_MAP,
                                             Text{ "Bottom of the Well Map", "Carte du fond du puits",
                                                   "Mapa del fondo del pozo", "Mappa del fondo del pozzo", "Deutsch" });
    itemTable[ICE_CAVERN_MAP] =
        Item(ITEMTYPE_MAP, 0xAE, false, &noVariable, ICE_CAVERN_MAP,
             Text{ "Ice Cavern Map", "Carte de la caverne polaire", "Mapa de la caverna de hielo",
                   "Mappa della caverna di ghiaccio", "Deutsch" });

    itemTable[DEKU_TREE_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0x9B, false, &noVariable, DEKU_TREE_COMPASS,
             Text{ "Great Deku Tree Compass", "Boussole de l'arbre Mojo", "Brújula del Gran Árbol Deku",
                   "Bussola del Grande Albero Deku", "Deutsch" });
    itemTable[DODONGOS_CAVERN_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0x9C, false, &noVariable, DODONGOS_CAVERN_COMPASS,
             Text{ "Dodongo's Cavern Compass", "Boussole de la grotte Dodongo", "Brújula de la Cueva de los Dodongos",
                   "Bussola della caverna dei Dodongo", "Deutsch" });
    itemTable[JABU_JABUS_BELLY_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0x9D, false, &noVariable, JABU_JABUS_BELLY_COMPASS,
             Text{ "Jabu-Jabu's Belly Compass", "Boussole de Jabu-Jabu", "Brújula de la tripa de Jabu-Jabu",
                   "Bussola della pancia di Jabu Jabu", "Deutsch" });
    itemTable[FOREST_TEMPLE_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0x9E, false, &noVariable, FOREST_TEMPLE_COMPASS,
             Text{ "Forest Temple Compass", "Boussole du temple de la forêt", "Brújula del Templo del Bosque",
                   "Bussola del Santuario della Foresta", "Deutsch" });
    itemTable[FIRE_TEMPLE_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0x9F, false, &noVariable, FIRE_TEMPLE_COMPASS,
             Text{ "Fire Temple Compass", "Boussole du temple du feu", "Brújula del Templo del Fuego",
                   "Bussola del Santuario del Fuoco", "Deutsch" });
    itemTable[WATER_TEMPLE_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0xA0, false, &noVariable, WATER_TEMPLE_COMPASS,
             Text{ "Water Temple Compass", "Boussole du temple de l'eau", "Brújula del Templo del Agua",
                   "Bussola del Santuario dell'Acqua", "Deutsch" });
    itemTable[SPIRIT_TEMPLE_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0xA1, false, &noVariable, SPIRIT_TEMPLE_COMPASS,
             Text{ "Spirit Temple Compass", "Boussole du temple de l'esprit", "Brújula del Templo del Espíritu",
                   "Bussola del Santuario dello Spirito", "Deutsch" });
    itemTable[SHADOW_TEMPLE_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0xA2, false, &noVariable, SHADOW_TEMPLE_COMPASS,
             Text{ "Shadow Temple Compass", "Boussole du temple de l'ombre", "Brújula del Templo de las Sombras",
                   "Bussola del Santuario dell'Ombra", "Deutsch" });
    itemTable[BOTTOM_OF_THE_WELL_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0xA3, false, &noVariable, BOTTOM_OF_THE_WELL_COMPASS,
             Text{ "Bottom of the Well Compass", "Boussole du fond du puits", "Brújula del fondo del pozo",
                   "Bussola del fondo del pozzo", "Deutsch" });
    itemTable[ICE_CAVERN_COMPASS] =
        Item(ITEMTYPE_COMPASS, 0xA4, false, &noVariable, ICE_CAVERN_COMPASS,
             Text{ "Ice Cavern Compass", "Boussole de la caverne polaire", "Brújula de la caverna de hielo",
                   "Bussola della caverna di ghiaccio", "Deutsch" });

    // Boss Keys
    itemTable[FOREST_TEMPLE_BOSS_KEY] =
        Item(ITEMTYPE_BOSSKEY, 0x95, true, &BossKeyForestTemple, FOREST_TEMPLE_BOSS_KEY,
             Text{ "Forest Temple Big Key", "Clé d'or du temple de la forêt", "Gran llave del Templo del Bosque",
                   "Grande chiave del Santuario della Foresta", "Deutsch" });
    itemTable[FIRE_TEMPLE_BOSS_KEY] =
        Item(ITEMTYPE_BOSSKEY, 0x96, true, &BossKeyFireTemple, FIRE_TEMPLE_BOSS_KEY,
             Text{ "Fire Temple Big Key", "Clé d'or du temple du feu", "Gran llave del Templo del Fuego",
                   "Grande chiave del Santuario del Fuoco", "Deutsch" });
    itemTable[WATER_TEMPLE_BOSS_KEY] =
        Item(ITEMTYPE_BOSSKEY, 0x97, true, &BossKeyWaterTemple, WATER_TEMPLE_BOSS_KEY,
             Text{ "Water Temple Big Key", "Clé d'or du temple de l'eau", "Gran llave del Templo del Agua",
                   "Grande chiave del Santuario dell'Acqua", "Deutsch" });
    itemTable[SPIRIT_TEMPLE_BOSS_KEY] =
        Item(ITEMTYPE_BOSSKEY, 0x98, true, &BossKeySpiritTemple, SPIRIT_TEMPLE_BOSS_KEY,
             Text{ "Spirit Temple Big Key", "Clé d'or du temple de l'esprit", "Gran llave del Templo del Espíritu",
                   "Grande chiave del Santuario dello Spirito", "Deutsch" });
    itemTable[SHADOW_TEMPLE_BOSS_KEY] =
        Item(ITEMTYPE_BOSSKEY, 0x99, true, &BossKeyShadowTemple, SHADOW_TEMPLE_BOSS_KEY,
             Text{ "Shadow Temple Big Key", "Clé d'or du temple de l'ombre", "Gran llave del Templo de las Sombras",
                   "Grande chiave del Santuario dell'Ombra", "Deutsch" });
    itemTable[GANONS_CASTLE_BOSS_KEY] =
        Item(ITEMTYPE_BOSSKEY, 0x9A, true, &BossKeyGanonsCastle, GANONS_CASTLE_BOSS_KEY,
             Text{ "Ganon's Castle Big Key", "Clé d'or du château de Ganon", "Gran llave del Castillo de Ganon",
                   "Grande chiave del castello di Ganon", "Deutsch" });

    // Small Keys
    itemTable[FOREST_TEMPLE_SMALL_KEY] =
        Item(ITEMTYPE_SMALLKEY, 0xAF, true, &ForestTempleKeys, FOREST_TEMPLE_SMALL_KEY,
             Text{ "Forest Temple Small Key", "Petite clé du temple de la forêt", "Llave del Templo del Bosque",
                   "Chiave del Santuario della Foresta", "Deutsch" });
    itemTable[FIRE_TEMPLE_SMALL_KEY] =
        Item(ITEMTYPE_SMALLKEY, 0xB0, true, &FireTempleKeys, FIRE_TEMPLE_SMALL_KEY,
             Text{ "Fire Temple Small Key", "Petite clé du temple du feu", "Llave del Templo del Fuego",
                   "Chiave del Santuario del Fuoco", "Deutsch" });
    itemTable[WATER_TEMPLE_SMALL_KEY] =
        Item(ITEMTYPE_SMALLKEY, 0xB1, true, &WaterTempleKeys, WATER_TEMPLE_SMALL_KEY,
             Text{ "Water Temple Small Key", "Petite clé du temple de l'eau", "Llave del Templo del Agua",
                   "Chiave del Santuario dell'Acqua", "Deutsch" });
    itemTable[SPIRIT_TEMPLE_SMALL_KEY] =
        Item(ITEMTYPE_SMALLKEY, 0xB2, true, &SpiritTempleKeys, SPIRIT_TEMPLE_SMALL_KEY,
             Text{ "Spirit Temple Small Key", "Petite clé du temple de l'esprit", "Llave del Templo del Espíritu",
                   "Chiave del Santuario dello Spirito", "Deutsch" });
    itemTable[SHADOW_TEMPLE_SMALL_KEY] =
        Item(ITEMTYPE_SMALLKEY, 0xB3, true, &ShadowTempleKeys, SHADOW_TEMPLE_SMALL_KEY,
             Text{ "Shadow Temple Small Key", "Petite clé du temple de l'ombre", "Llave del Templo de las Sombras",
                   "Chiave del Santuario dell'Ombra", "Deutsch" });
    itemTable[BOTTOM_OF_THE_WELL_SMALL_KEY] =
        Item(ITEMTYPE_SMALLKEY, 0xB4, true, &BottomOfTheWellKeys, BOTTOM_OF_THE_WELL_SMALL_KEY,
             Text{ "Bottom of the Well Small Key", "Petite clé du fond du puits", "Llave del fondo del pozo",
                   "Chiave del fondo del pozzo", "Deutsch" });
    itemTable[GERUDO_TRAINING_GROUNDS_SMALL_KEY] =
        Item(ITEMTYPE_SMALLKEY, 0xB5, true, &GerudoTrainingGroundsKeys, GERUDO_TRAINING_GROUNDS_SMALL_KEY,
             Text{ "Training Grounds Small Key", "Petite clé du gymnase Gerudo", "Llave del Centro de Instrucción",
                   "Chiave della zona di addestramento", "Deutsch" });
    itemTable[GERUDO_FORTRESS_SMALL_KEY] =
        Item(ITEMTYPE_FORTRESS_SMALLKEY, 0xB6, true, &GerudoFortressKeys, GERUDO_FORTRESS_SMALL_KEY,
             Text{ "Gerudo Fortress Small Key", "Petite clé du repaire Gerudo", "Llave de la Fortaleza Gerudo",
                   "Chiave della fortezza Gerudo", "Deutsch" });
    itemTable[GANONS_CASTLE_SMALL_KEY] =
        Item(ITEMTYPE_SMALLKEY, 0xB7, true, &GanonsCastleKeys, GANONS_CASTLE_SMALL_KEY,
             Text{ "Ganon's Castle Small Key", "Petite clé du château de Ganon", "Llave del Castillo de Ganon",
                   "Chiave del castello di Ganon", "Deutsch" });
    itemTable[TREASURE_GAME_SMALL_KEY] =
        Item(ITEMTYPE_ITEM, 0xDE, true, &TreasureGameKeys, TREASURE_GAME_SMALL_KEY,
             Text{ "Chest Game Small Key", "Clé de la chasse-aux-trésors", "Llave del Cofre del Tesoro",
                   "Chiave della sala della fortuna", "Deutsch" });

    // Key Rings
    itemTable[FOREST_TEMPLE_KEY_RING] =
        Item(ITEMTYPE_SMALLKEY, 0xD5, true, &ForestTempleKeys, FOREST_TEMPLE_KEY_RING,
             Text{ "Forest Temple Key Ring", "Trousseau du temple de la forêt", "Llavero del Templo del Bosque",
                   "Chiavi del Santuario della Foresta", "Deutsch" });
    itemTable[FIRE_TEMPLE_KEY_RING] =
        Item(ITEMTYPE_SMALLKEY, 0xD6, true, &FireTempleKeys, FIRE_TEMPLE_KEY_RING,
             Text{ "Fire Temple Key Ring", "Trousseau du temple du feu", "Llavero del Templo del Fuego",
                   "Chiavi del Santuario del Fuoco", "Deutsch" });
    itemTable[WATER_TEMPLE_KEY_RING] =
        Item(ITEMTYPE_SMALLKEY, 0xD7, true, &WaterTempleKeys, WATER_TEMPLE_KEY_RING,
             Text{ "Water Temple Key Ring", "Trousseau du temple de l'eau", "Llavero del Templo del Agua",
                   "Chiavi del Santuario dell'Acqua", "Deutsch" });
    itemTable[SPIRIT_TEMPLE_KEY_RING] =
        Item(ITEMTYPE_SMALLKEY, 0xD8, true, &SpiritTempleKeys, SPIRIT_TEMPLE_KEY_RING,
             Text{ "Spirit Temple Key Ring", "Trousseau du temple de l'esprit", "Llavero del Templo del Espíritu",
                   "Chiavi del Santuario dello Spirito", "Deutsch" });
    itemTable[SHADOW_TEMPLE_KEY_RING] =
        Item(ITEMTYPE_SMALLKEY, 0xD9, true, &ShadowTempleKeys, SHADOW_TEMPLE_KEY_RING,
             Text{ "Shadow Temple Key Ring", "Trousseau du temple de l'ombre", "Llavero del Templo de las Sombras",
                   "Chiavi del Santuario dell'Ombra", "Deutsch" });
    itemTable[BOTTOM_OF_THE_WELL_KEY_RING] =
        Item(ITEMTYPE_SMALLKEY, 0xDA, true, &BottomOfTheWellKeys, BOTTOM_OF_THE_WELL_KEY_RING,
             Text{ "Bottom of the Well Key Ring", "Trousseau du fond du puits", "Llavero del fondo del pozo",
                   "Chiavi del fondo del pozzo", "Deutsch" });
    itemTable[GERUDO_TRAINING_GROUNDS_KEY_RING] =
        Item(ITEMTYPE_SMALLKEY, 0xDB, true, &GerudoTrainingGroundsKeys, GERUDO_TRAINING_GROUNDS_KEY_RING,
             Text{ "Training Grounds Key Ring", "Trousseau du gymnase Gerudo", "Llavero del Centro de Instrucción",
                   "Chiavi della zona di addestramento", "Deutsch" });
    itemTable[GERUDO_FORTRESS_KEY_RING] =
        Item(ITEMTYPE_FORTRESS_SMALLKEY, 0xDC, true, &GerudoFortressKeys, GERUDO_FORTRESS_KEY_RING,
             Text{ "Gerudo Fortress Key Ring", "Trousseau du repaire Gerudo", "Llavero de la Fortaleza Gerudo",
                   "Chiavi della fortezza Gerudo", "Deutsch" });
    itemTable[GANONS_CASTLE_KEY_RING] =
        Item(ITEMTYPE_SMALLKEY, 0xDD, true, &GanonsCastleKeys, GANONS_CASTLE_KEY_RING,
             Text{ "Ganon's Castle Key Ring", "Trousseau du château de Ganon", "Llavero del Castillo de Ganon",
                   "Chiavi del castello di Ganon", "Deutsch" });

    // Stones and Medallions
    itemTable[KOKIRI_EMERALD] = Item(ITEMTYPE_DUNGEONREWARD, 0xCB, true, &KokiriEmerald, KOKIRI_EMERALD,
                                     Text{ "Kokiri's Emerald", "Émeraude Kokiri", "Esmeralda de los Kokiri",
                                           "Smeraldo dei Kokiri", "Kokiri-Smaragd" });
    itemTable[GORON_RUBY] =
        Item(ITEMTYPE_DUNGEONREWARD, 0xCC, true, &GoronRuby, GORON_RUBY,
             Text{ "Goron's Ruby", "Rubis Goron", "Rubí de los Goron", "Rubino dei Goron", "Goronen-Rubin" });
    itemTable[ZORA_SAPPHIRE] =
        Item(ITEMTYPE_DUNGEONREWARD, 0xCD, true, &ZoraSapphire, ZORA_SAPPHIRE,
             Text{ "Zora's Sapphire", "Saphir Zora", "Zafiro de los Zora", "Zaffiro degli Zora", "Zora-Saphir" });
    itemTable[FOREST_MEDALLION] = Item(ITEMTYPE_DUNGEONREWARD, 0xCE, true, &ForestMedallion, FOREST_MEDALLION,
                                       Text{ "Forest Medallion", "Médaillon de la forêt", "Medallón del Bosque",
                                             "Medaglione della Foresta", "Amulett des Waldes" });
    itemTable[FIRE_MEDALLION] = Item(ITEMTYPE_DUNGEONREWARD, 0xCF, true, &FireMedallion, FIRE_MEDALLION,
                                     Text{ "Fire Medallion", "Médaillon du feu", "Medallón del Fuego",
                                           "Medaglione del Fuoco", "Amulett des Feuers" });
    itemTable[WATER_MEDALLION] = Item(ITEMTYPE_DUNGEONREWARD, 0xD0, true, &WaterMedallion, WATER_MEDALLION,
                                      Text{ "Water Medallion", "Médaillon de l'eau", "Medallón del Agua",
                                            "Medaglione dell'Acqua", "Amulett des Wassers" });
    itemTable[SPIRIT_MEDALLION] = Item(ITEMTYPE_DUNGEONREWARD, 0xD1, true, &SpiritMedallion, SPIRIT_MEDALLION,
                                       Text{ "Spirit Medallion", "Médaillon de l'esprit", "Medallón del Espíritu",
                                             "Medaglione dello Spirito", "Amulett der Geister" });
    itemTable[SHADOW_MEDALLION] = Item(ITEMTYPE_DUNGEONREWARD, 0xD2, true, &ShadowMedallion, SHADOW_MEDALLION,
                                       Text{ "Shadow Medallion", "Médaillon de l'ombre", "Medallón de la Sombra",
                                             "Medaglione dell'Ombra", "Amulett des Schattens" });
    itemTable[LIGHT_MEDALLION] = Item(ITEMTYPE_DUNGEONREWARD, 0xD3, true, &LightMedallion, LIGHT_MEDALLION,
                                      Text{ "Light Medallion", "Médaillon de la lumière", "Medallón de la Luz",
                                            "Medaglione della Luce", "Amulett des Lichts" });

    // Generic Items
    itemTable[RECOVERY_HEART] = Item(ITEMTYPE_ITEM, GI_HEART, false, &noVariable, RECOVERY_HEART,
                                     Text{ "Recovery Heart", "Cœur d'énergie", "Corazón", "Cuore", "Herz" });
    itemTable[GREEN_RUPEE] = Item(ITEMTYPE_ITEM, GI_RUPEE_GREEN, false, &noVariable, GREEN_RUPEE,
                                  Text{ "Green Rupee", "Rubis vert", "Rupia verde", "Rupia verde", "Deutsch" });
    itemTable[BLUE_RUPEE] = Item(ITEMTYPE_ITEM, GI_RUPEE_BLUE, false, &noVariable, BLUE_RUPEE,
                                 Text{ "Blue Rupee", "Rubis bleu", "Rupia azul", "Rupia blu", "Deutsch" });
    itemTable[RED_RUPEE] = Item(ITEMTYPE_ITEM, GI_RUPEE_RED, false, &noVariable, RED_RUPEE,
                                Text{ "Red Rupee", "Rubis rouge", "Rupia roja", "Rupia rossa", "Deutsch" });
    itemTable[PURPLE_RUPEE] = Item(ITEMTYPE_ITEM, GI_RUPEE_PURPLE, false, &noVariable, PURPLE_RUPEE,
                                   Text{ "Purple Rupee", "Rubis pourpre", "Rupia morada", "Rupia viola", "Deutsch" });
    itemTable[HUGE_RUPEE] = Item(ITEMTYPE_ITEM, GI_RUPEE_GOLD, false, &noVariable, HUGE_RUPEE,
                                 Text{ "Huge Rupee", "Énorme rubis", "Rupia gigante", "Rupia gigante", "Deutsch" });
    itemTable[PIECE_OF_HEART] =
        Item(ITEMTYPE_ITEM, GI_HEART_PIECE, true, &PieceOfHeart, PIECE_OF_HEART,
             Text{ "Piece of Heart", "Quart de cœur", "Pieza de corazón", "Frammento di cuore", "Deutsch" });
    itemTable[HEART_CONTAINER] =
        Item(ITEMTYPE_ITEM, GI_HEART_CONTAINER_2, true, &HeartContainer, HEART_CONTAINER,
             Text{ "Heart Container", "Réceptacle de cœur", "Contenedor de corazón", "Portacuori", "Deutsch" });
    itemTable[ICE_TRAP] =
        Item(ITEMTYPE_ITEM, GI_ICE_TRAP, false, &noVariable, ICE_TRAP,
             Text{ "Ice Trap", "Piège de glace", "Trampa de hielo", "Trappola di ghiaccio", "Deutsch" });
    itemTable[MILK] = Item(ITEMTYPE_ITEM, GI_MILK, false, &noVariable, NONE,
                           Text{ "Milk", "Lait", "Leche Lon Lon", "Latte Lon Lon", "Deutsch" });

    // Refills
    itemTable[BOMBS_5] = Item(ITEMTYPE_REFILL, GI_BOMBS_5, false, &noVariable, BOMBS_5,
                              Text{ "Bombs (5)", "Bombes (5)", "Bombas (5)", "5 bombe", "Deutsch" });
    itemTable[BOMBS_10] = Item(ITEMTYPE_REFILL, GI_BOMBS_10, false, &noVariable, BOMBS_10,
                               Text{ "Bombs (10)", "Bombes (10)", "Bombas (10)", "10 bombe", "Deutsch" });
    itemTable[BOMBS_20] = Item(ITEMTYPE_REFILL, GI_BOMBS_20, false, &noVariable, BOMBS_20,
                               Text{ "Bombs (20)", "Bombes (20)", "Bombas (20)", "20 bombe", "Deutsch" });
    itemTable[BOMBCHU_5] = Item(ITEMTYPE_REFILL, GI_BOMBCHUS_5, true, &Bombchus5, BOMBCHU_5,
                                Text{ "Bombchu (5)", "Bombchus (5)", "Bombchus (5)", "5 radiomine", "Deutsch" });
    itemTable[BOMBCHU_10] = Item(ITEMTYPE_REFILL, GI_BOMBCHUS_10, true, &Bombchus10, BOMBCHU_10,
                                 Text{ "Bombchu (10)", "Bombchus (10)", "Bombchus (10)", "10 radiomine", "Deutsch" });
    itemTable[BOMBCHU_20] = Item(ITEMTYPE_REFILL, GI_BOMBCHUS_20, true, &Bombchus20, BOMBCHU_20,
                                 Text{ "Bombchu (20)", "Bombchus (20)", "Bombchus (20)", "20 radiomine", "Deutsch" });
    itemTable[BOMBCHU_DROP] = Item(ITEMTYPE_DROP, GI_BOMBCHUS_10, true, &BombchuDrop, NONE,
                                   Text{ "Bombchu Drop", "Bombchus", "Bombchus", "Drop di radiomine", "Deutsch" });
    itemTable[ARROWS_5] = Item(ITEMTYPE_REFILL, GI_ARROWS_SMALL, false, &noVariable, ARROWS_5,
                               Text{ "Arrows (5)", "Flèches (5)", "Flechas (5)", "5 frecce", "Deutsch" });
    itemTable[ARROWS_10] = Item(ITEMTYPE_REFILL, GI_ARROWS_MEDIUM, false, &noVariable, ARROWS_10,
                                Text{ "Arrows (10)", "Flèches (10)", "Flechas (10)", "10 frecce", "Deutsch" });
    itemTable[ARROWS_30] = Item(ITEMTYPE_REFILL, GI_ARROWS_LARGE, false, &noVariable, ARROWS_30,
                                Text{ "Arrows (30)", "Flèches (30)", "Flechas (30)", "30 frecce", "Deutsch" });
    itemTable[DEKU_NUTS_5] =
        Item(ITEMTYPE_REFILL, GI_NUTS_5, false, &noVariable, DEKU_NUTS_5,
             Text{ "Deku Nuts (5)", "Noix Mojo (5)", "Nueces deku (5)", "5 noci Deku", "Deutsch" });
    itemTable[DEKU_NUTS_10] =
        Item(ITEMTYPE_REFILL, GI_NUTS_10, false, &noVariable, DEKU_NUTS_10,
             Text{ "Deku Nuts (10)", "Noix Mojo (10)", "Nueces deku (10)", "10 noci Deku", "Deutsch" });
    itemTable[DEKU_SEEDS_30] =
        Item(ITEMTYPE_REFILL, GI_SEEDS_30, false, &noVariable, DEKU_SEEDS_30,
             Text{ "Deku Seeds (30)", "Graines Mojo (30)", "Semillas deku (30)", "30 semi Deku", "Deutsch" });
    itemTable[DEKU_STICK_1] =
        Item(ITEMTYPE_REFILL, GI_STICKS_1, false, &noVariable, DEKU_STICK_1,
             Text{ "Deku Stick (1)", "Bâton Mojo (1)", "Palo deku (1)", "1 ramo Deku", "Deutsch" });
    itemTable[RED_POTION_REFILL] =
        Item(ITEMTYPE_REFILL, GI_POTION_RED, false, &noVariable, NONE,
             Text{ "Red Potion Refill", "Potion rouge", "Recarga de poción roja", "Dose di pozione vita", "Deutsch" });
    itemTable[GREEN_POTION_REFILL] = Item(
        ITEMTYPE_REFILL, GI_POTION_GREEN, false, &noVariable, NONE,
        Text{ "Green Potion Refill", "Potion verte", "Recarga de poción verde", "Dose di pozione magica", "Deutsch" });
    itemTable[BLUE_POTION_REFILL] = Item(
        ITEMTYPE_REFILL, GI_POTION_BLUE, false, &noVariable, NONE,
        Text{ "Blue Potion Refill", "Potion bleue", "Recarga de poción azul", "Dose di pozione curatutto", "Deutsch" });

    // Treasure Game
    itemTable[TREASURE_GAME_HEART] =
        Item(ITEMTYPE_ITEM, GI_HEART_PIECE_WIN, true, &PieceOfHeart, TREASURE_GAME_HEART,
             Text{ "Piece of Heart (Treasure Chest Minigame)", "Quart de cœur (Chasse-aux-trésors)",
                   "Pieza de corazón (Cofre del Tesoro)", "Frammento di cuore (sala della fortuna)", "Deutsch" });
    itemTable[TREASURE_GAME_GREEN_RUPEE] =
        Item(ITEMTYPE_ITEM, GI_RUPEE_GREEN_LOSE, false, &noVariable, TREASURE_GAME_GREEN_RUPEE,
             Text{ "Green Rupee (Treasure Chest Minigame)", "Rubis vert (Chasse-aux-trésors)",
                   "Rupia Verde (Cofre del Tesoro)", "Rupia verde (sala della fortuna)", "Deutsch" });

    // Shop Items price
    itemTable[BUY_DEKU_NUT_5] = Item(ITEMTYPE_SHOP, 0x00, true, &Nuts, DEKU_NUTS_5, 15,
                                     Text{ "Buy Deku Nut (5)", "Acheter: Noix Mojo (5)", "Comprar nueces deku (5)",
                                           "5 noci Deku in vendita", "Deutsch" });
    itemTable[BUY_ARROWS_30] = Item(
        ITEMTYPE_SHOP, 0x01, true, &BuyArrow, ARROWS_30, 60,
        Text{ "Buy Arrows (30)", "Acheter: Flèches (30)", "Comprar flechas (30)", "30 frecce in vendita", "Deutsch" });
    itemTable[BUY_ARROWS_50] = Item(
        ITEMTYPE_SHOP, 0x02, true, &BuyArrow, ARROWS_30, 90,
        Text{ "Buy Arrows (50)", "Acheter: Flèches (50)", "Comprar flechas (50)", "50 frecce in vendita", "Deutsch" });
    itemTable[BUY_BOMBS_525] = Item(ITEMTYPE_SHOP, 0x03, true, &BuyBomb, BOMBS_5, 25,
                                    Text{ "Buy Bombs (5) [25]", "Acheter: Bombes (5) [25]", "Comprar bombas (5) [25]",
                                          "5 bombe in vendita [25]", "Deutsch" });
    itemTable[BUY_DEKU_NUT_10] = Item(ITEMTYPE_SHOP, 0x04, true, &Nuts, DEKU_NUTS_10, 30,
                                      Text{ "Buy Deku Nut (10)", "Acheter: Noix Mojo (10)", "Comprar Nueces deku (10)",
                                            "10 noci Deku in vendita", "Deutsch" });
    itemTable[BUY_DEKU_STICK_1] = Item(ITEMTYPE_SHOP, 0x05, true, &Sticks, DEKU_STICK_1, 10,
                                       Text{ "Buy Deku Stick (1)", "Acheter: Bâton Mojo (1)", "Comprar palos deku (1)",
                                             "1 ramo Deku in vendita", "Deutsch" });
    itemTable[BUY_BOMBS_10] =
        Item(ITEMTYPE_SHOP, 0x06, true, &BuyBomb, BOMBS_10, 50,
             Text{ "Buy Bombs (10)", "Acheter: Bombes (10)", "Comprar Bombas (10)", "10 bombe in vendita", "Deutsch" });
    itemTable[BUY_FISH] = Item(ITEMTYPE_SHOP, 0x07, true, &FishAccess, BOTTLE_WITH_FISH, 200,
                               Text{ "Buy Fish", "Acheter: Poisson", "Comprar pez", "Pesce in vendita", "Deutsch" });
    itemTable[BUY_RED_POTION_30] = Item(ITEMTYPE_SHOP, 0x08, false, &noVariable, BOTTLE_WITH_RED_POTION, 30,
                                        Text{ "Buy Red Potion [30]", "Acheter: Potion rouge [30]",
                                              "Comprar poción roja [30]", "Pozione vita in vendita [30]", "Deutsch" });
    itemTable[BUY_GREEN_POTION] = Item(ITEMTYPE_SHOP, 0x09, true, &BuyGPotion, BOTTLE_WITH_GREEN_POTION, 30,
                                       Text{ "Buy Green Potion", "Acheter: Potion verte", "Comprar poción verde",
                                             "Pozione magica in vendita", "Deutsch" });
    itemTable[BUY_BLUE_POTION] = Item(ITEMTYPE_SHOP, 0x0A, true, &BuyBPotion, BOTTLE_WITH_BLUE_POTION, 100,
                                      Text{ "Buy Blue Potion", "Acheter: Potion bleue", "Comprar poción azul",
                                            "Pozione curatutto in vendita", "Deutsch" });
    itemTable[BUY_HYLIAN_SHIELD] = Item(ITEMTYPE_SHOP, 0x0C, true, &HylianShield, HYLIAN_SHIELD, 80,
                                        Text{ "Buy Hylian Shield", "Acheter: Bouclier Hylien", "Comprar escudo hyliano",
                                              "Scudo Hylia in vendita", "Deutsch" });
    itemTable[BUY_DEKU_SHIELD] = Item(
        ITEMTYPE_SHOP, 0x0D, true, &DekuShield, DEKU_SHIELD, 40,
        Text{ "Buy Deku Shield", "Acheter: Bouclier Mojo", "Comprar escudo deku", "Scudo Deku in vendita", "Deutsch" });
    itemTable[BUY_GORON_TUNIC] = Item(ITEMTYPE_SHOP, 0x0E, true, &GoronTunic, GORON_TUNIC, 200,
                                      Text{ "Buy Goron Tunic", "Acheter: Tunique Goron", "Comprar sayo goron",
                                            "Veste dei Goron in vendita", "Deutsch" });
    itemTable[BUY_ZORA_TUNIC] = Item(ITEMTYPE_SHOP, 0x0F, true, &ZoraTunic, ZORA_TUNIC, 300,
                                     Text{ "Buy Zora Tunic", "Acheter: Tunique Zora", "Comprar sayo zora",
                                           "Veste degli Zora in vendita", "Deutsch" });
    itemTable[BUY_HEART] =
        Item(ITEMTYPE_SHOP, 0x10, false, &noVariable, RECOVERY_HEART, 10,
             Text{ "Buy Heart", "Acheter: Coeur d'énergie", "Comprar corazón", "Cuore in vendita", "Deutsch" });
    itemTable[BUY_BOMBCHU_10] = Item(ITEMTYPE_SHOP, 0x15, true, &BuyBombchus10, BOMBCHU_10, 99,
                                     Text{ "Buy Bombchu (10)", "Acheter: Bombchus (10)", "Comprar bombchus (10)",
                                           "10 radiomine in vendita", "Deutsch" });
    itemTable[BUY_BOMBCHU_20] = Item(ITEMTYPE_SHOP, 0x16, true, &BuyBombchus20, BOMBCHU_20, 180,
                                     Text{ "Buy Bombchu (20)", "Acheter: Bombchus (20)", "Comprar bombchus (20)",
                                           "20 radiomine in vendita", "Deutsch" });
    itemTable[BUY_BOMBCHU_5] = Item(ITEMTYPE_SHOP, 0x18, true, &BuyBombchus5, BOMBCHU_5, 60,
                                    Text{ "Buy Bombchu (5)", "Acheter: Bombchus (5)", "Comprar bombchus (5)",
                                          "5 radiomine in vendita", "Deutsch" });
    itemTable[BUY_DEKU_SEEDS_30] = Item(ITEMTYPE_SHOP, 0x1D, true, &BuySeed, DEKU_SEEDS_30, 30,
                                        Text{ "Buy Deku Seeds (30)", "Acheter: Graines Mojo (30)",
                                              "Comprar semillas deku (30)", "30 semi Deku in vendita", "Deutsch" });
    itemTable[SOLD_OUT] = Item(ITEMTYPE_SHOP, 0x26, false, &noVariable, NONE, 0,
                               Text{ "Sold Out", "Vendu", "Vendido", "Venduto", "Deutsch" });
    itemTable[BUY_BLUE_FIRE] =
        Item(ITEMTYPE_SHOP, 0x27, true, &BlueFireAccess, BOTTLE_WITH_BLUE_FIRE, 300,
             Text{ "Buy Blue Fire", "Acheter: Flamme bleue", "Comprar fuego azul", "Fuoco blu in vendita", "Deutsch" });
    itemTable[BUY_BOTTLE_BUG] = Item(
        ITEMTYPE_SHOP, 0x28, true, &BugsAccess, BOTTLE_WITH_BUGS, 50,
        Text{ "Buy Bottle Bug", "Acheter: Insectes en flacon", "Comprar bichos", "Insetto in vendita", "Deutsch" });
    itemTable[BUY_POE] = Item(ITEMTYPE_SHOP, 0x2A, false, &noVariable, BOTTLE_WITH_BIG_POE, 30,
                              Text{ "Buy Poe", "Acheter: Esprit", "Comprar Poe", "Poo in vendita", "Deutsch" });
    itemTable[BUY_FAIRYS_SPIRIT] =
        Item(ITEMTYPE_SHOP, 0x2B, true, &FairyAccess, BOTTLE_WITH_FAIRY, 50,
             Text{ "Buy Fairy's Spirit", "Acheter: Fée", "Comprar hada", "Fata in vendita", "Deutsch" });
    itemTable[BUY_ARROWS_10] = Item(
        ITEMTYPE_SHOP, 0x2C, true, &BuyArrow, ARROWS_10, 20,
        Text{ "Buy Arrows (10)", "Acheter: Flèches (10)", "Comprar flechas (10)", "10 frecce in vendita", "Deutsch" });
    itemTable[BUY_BOMBS_20] =
        Item(ITEMTYPE_SHOP, 0x2D, true, &BuyBomb, BOMBS_20, 80,
             Text{ "Buy Bombs (20)", "Acheter: Bombes (20)", "Comprar bombas (20)", "20 bombe in vendita", "Deutsch" });
    itemTable[BUY_BOMBS_30] =
        Item(ITEMTYPE_SHOP, 0x2E, true, &BuyBomb, BOMBS_20, 120,
             Text{ "Buy Bombs (30)", "Acheter: Bombes (30)", "Comprar bombas (30)", "30 bombe in vendita", "Deutsch" });
    itemTable[BUY_BOMBS_535] = Item(ITEMTYPE_SHOP, 0x2F, true, &BuyBomb, BOMBS_5, 35,
                                    Text{ "Buy Bombs (5) [35]", "Acheter: Bombes (5) [35]", "Comprar bombas (5) [35]",
                                          "5 bombe in vendita [35]", "Deutsch" });
    itemTable[BUY_RED_POTION_40] = Item(ITEMTYPE_SHOP, 0x30, false, &noVariable, BOTTLE_WITH_RED_POTION, 40,
                                        Text{ "Buy Red Potion [40]", "Acheter: Potion rouge [40]",
                                              "Comprar poción roja [40]", "Pozione vita in vendita [40]", "Deutsch" });
    itemTable[BUY_RED_POTION_50] = Item(ITEMTYPE_SHOP, 0x31, false, &noVariable, BOTTLE_WITH_RED_POTION, 50,
                                        Text{ "Buy Red Potion [50]", "Acheter: Potion rouge [50]",
                                              "Comprar poción roja [50]", "Pozione vita in vendita [50]", "Deutsch" });

    itemTable[TRIFORCE] = Item(ITEMTYPE_EVENT, GI_RUPEE_RED_LOSE, false, &noVariable, NONE,
                               Text{ "Triforce", "Triforce", "Trifuerza", "Triforza", "Deutsch" });
    itemTable[HINT] = Item(ITEMTYPE_EVENT, GI_RUPEE_BLUE_LOSE, false, &noVariable, NONE,
                           Text{ "Hint", "Indice", "Pista", "Indizio", "Deutsch" });

    //  itemTable[HOOKSHOT]                          = Item(ITEMTYPE_ITEM,              0x80,                 true,
    //  &ProgressiveHookshot,       HOOKSHOT,                          Text{"Hookshot", "Grappin", "Gancho", "Arpione",
    //  "Fanghaken"}); itemTable[LONGSHOT]                          = Item(ITEMTYPE_ITEM,              0x80, true,
    //  &ProgressiveHookshot,       LONGSHOT,                          Text{"Longshot", "Super-Grappin", "Supergancho",
    //  "Super arpione",                            "Enterhaken"}); itemTable[FAIRY_OCARINA]                     =
    //  Item(ITEMTYPE_ITEM,              0x8B,                 true,        &ProgressiveOcarina,        FAIRY_OCARINA,
    //  Text{"Fairy Ocarina",                   "Ocarina des fées",                 "Ocarina de las Hadas", "Ocarina
    //  magica",                           "Feen-Okarina"}); itemTable[OCARINA_OF_TIME]                   =
    //  Item(ITEMTYPE_ITEM,              0x8B,                 true,        &ProgressiveOcarina,        OCARINA_OF_TIME,
    //  Text{"Ocarina of Time",                 "Ocarina du temps",                 "Ocarina del Tiempo", "Ocarina del
    //  Tempo",                        "Okarina der Zeit"}); itemTable[BOMB_BAG]                          =
    //  Item(ITEMTYPE_ITEM,              0x82,                 true,        &ProgressiveBombBag,        BOMB_BAG,
    //  Text{"Bomb Bag",                        "Sac de bombes",                    "Saco de bombas", "Portabombe (20
    //  bombe)",                    "Bombentasche"}); itemTable[BIG_BOMB_BAG]                      = Item(ITEMTYPE_ITEM,
    //  0x82,                 true,        &ProgressiveBombBag,        BIG_BOMB_BAG,                      Text{"Big Bomb
    //  Bag",                    "Grand sac de bombes",              "Saco de bombas grande", "Portabombe grande (30
    //  bombe)",             "Deutsch"}); itemTable[BIGGEST_BOMB_BAG]                  = Item(ITEMTYPE_ITEM, 0x82, true,
    //  &ProgressiveBombBag,        BIGGEST_BOMB_BAG,                  Text{"Biggest Bomb Bag",                "Énorme
    //  sac de bombes",             "Saco de bombas gigante",                   "Mega portabombe (40 bombe)",
    //  "Riesen-Bombentasche"}); itemTable[FAIRY_BOW]                         = Item(ITEMTYPE_ITEM,              0x83,
    //  true,        &ProgressiveBow,            FAIRY_BOW,                         Text{"Fairy Bow", "Arc des fées",
    //  "Arco de las Hadas",                        "Arco magico",                              "Feen-Bogen"});
    //  itemTable[BIG_QUIVER]                        = Item(ITEMTYPE_ITEM,              0x83,                 true,
    //  &ProgressiveBow,            BIG_QUIVER,                        Text{"Big Quiver",                      "Grand
    //  carquois",                   "Carcaj grande",                            "Faretra grande (40 frecce)",
    //  "Deutsch"}); itemTable[BIGGEST_QUIVER]                    = Item(ITEMTYPE_ITEM,              0x83, true,
    //  &ProgressiveBow,            BIGGEST_QUIVER,                    Text{"Biggest Quiver",                  "Énorme
    //  carquois",                  "Carcaj gigante",                           "Mega faretra (50 frecce)", "Deutsch"});
    //  itemTable[FAIRY_SLINGSHOT]                   = Item(ITEMTYPE_ITEM,              0x84,                 true,
    //  &ProgressiveBulletBag,      FAIRY_SLINGSHOT,                   Text{"Fairy Slingshot", "Lance-pierre des fées",
    //  "Resortera de las hadas",                   "Fionda magica",                            "Feen-Schleuder"});
    //  itemTable[BIG_BULLET_BAG]                    = Item(ITEMTYPE_ITEM,              0x84,                 true,
    //  &ProgressiveBulletBag,      BIG_BULLET_BAG,                    Text{"Big Deku Seed Bullet Bag",        "Grand
    //  sac de graines mojo",        "Bolsa de semillas deku grande",            "Grande portasemi Deku (40 semi)",
    //  "Deutsch"}); itemTable[BIGGEST_BULLET_BAD]                = Item(ITEMTYPE_ITEM,              0x84, true,
    //  &ProgressiveBulletBag,      BIGGEST_BULLET_BAD,                Text{"Biggest Deku Seed Bullet Bag",    "Énorme
    //  sac de graines mojo",       "Bolsa de semillas deku gigante",           "Mega portasemi Deku (50 semi)",
    //  "Deutsch"}); itemTable[GORONS_BRACELET]                   = Item(ITEMTYPE_ITEM,              0x81, true,
    //  &ProgressiveStrength,       GORONS_BRACELET,                   Text{"Goron's Bracelet",                "Bracelet
    //  Goron",                   "Brazalete de los Goron",                   "Bracciale dei Goron",
    //  "Goronen-Armband"}); itemTable[SILVER_GAUNTLETS]                  = Item(ITEMTYPE_ITEM,              0x81, true,
    //  &ProgressiveStrength,       SILVER_GAUNTLETS,                  Text{"Silver Gauntlets", "Gantelets d'argent",
    //  "Guantes de plata",                         "Guanti d'argento",                         "Silberhandschuhe"});
    //  itemTable[GOLDEN_GAUNTLETS]                  = Item(ITEMTYPE_ITEM,              0x81,                 true,
    //  &ProgressiveStrength,       GOLDEN_GAUNTLETS,                  Text{"Golden Gauntlets", "Gantelets d'or",
    //  "Guantes de oro",                           "Guanti d'oro",                             "Goldhandschuhe"});
    //  itemTable[SILVER_SCALE]                      = Item(ITEMTYPE_ITEM,              0x86,                 true,
    //  &ProgressiveScale,          SILVER_SCALE,                      Text{"Silver Scale",                    "Écaille
    //  d'argent",                 "Escama de Plata",                          "Squama d'argento", "Silberne Schuppe"});
    //  itemTable[GOLDEN_SCALE]                      = Item(ITEMTYPE_ITEM,              0x86,                 true,
    //  &ProgressiveScale,          GOLDEN_SCALE,                      Text{"Golden Scale",                    "Écaille
    //  d'or",                     "Escama de Oro",                            "Squama d'oro", "Goldene Schuppe"});
    //  itemTable[ADULT_WALLET]                      = Item(ITEMTYPE_ITEM,              0x85,                 true,
    //  &ProgressiveWallet,         ADULT_WALLET,                      Text{"Adult Wallet",                    "Bourse
    //  d'adulte",                  "Bolsa de adulto",                          "Portarupie da adulto", "Deutsch"});
    //  itemTable[GIANT_WALLET]                      = Item(ITEMTYPE_ITEM,              0x85,                 true,
    //  &ProgressiveWallet,         GIANT_WALLET,                      Text{"Giant Wallet",                    "Bourse
    //  de géant",                  "Bolsa gigante",                            "Portarupie del gigante", "Deutsch"});
    //  itemTable[TYCOON_WALLET]                     = Item(ITEMTYPE_ITEM,              0x85,                 true,
    //  &ProgressiveWallet,         TYCOON_WALLET,                     Text{"Tycoon Wallet",                   "Bourse
    //  de star",                   "Bolsa de ricachón",                        "Portarupie di lusso", "Deutsch"});
    //  itemTable[DEKU_NUT_CAPACITY_30]              = Item(ITEMTYPE_ITEM,              0x87,                 false,
    //  &noVariable,                DEKU_NUT_CAPACITY_30,              Text{"Deku Nut Capacity (30)",          "Capacité
    //  de noix Mojo (20)",       "Capacidad de nueces deku (40)",            "Capacità di noci Deku (40)", "Deutsch"});
    //  itemTable[DEKU_NUT_CAPACITY_40]              = Item(ITEMTYPE_ITEM,              0x87,                 false,
    //  &noVariable,                DEKU_NUT_CAPACITY_40,              Text{"Deku Nut Capacity (40)",          "Capacité
    //  de noix Mojo (30)",       "Capacidad de nueces deku (50)",            "Capacità di noci Deku (50)", "Deutsch"});
    //  itemTable[DEKU_NUT_CAPACITY_20]              = Item(ITEMTYPE_ITEM,              0x88,                 false,
    //  &noVariable,                DEKU_NUT_CAPACITY_20,              Text{"Deku Stick Capacity (20)",        "Capacité
    //  de bâtons Mojo (20)",     "Capacidad de palos deku (20)",             "Capacità di rami Deku (20)", "Deutsch"});
    //  itemTable[DEKU_NUT_CAPACITY_30]              = Item(ITEMTYPE_ITEM,              0x88,                 false,
    //  &noVariable,                DEKU_NUT_CAPACITY_30,              Text{"Deku Nut Capacity (30)",          "Capacité
    //  de noix Mojo (20)",       "Capacidad de nueces deku (40)",            "Capacità di rami Deku (30)", "Deutsch"});
    //  itemTable[MAGIC_METER]                       = Item(ITEMTYPE_ITEM,              0x8A,                 true,
    //  &ProgressiveMagic,          MAGIC_METER,                       Text{"Magic Meter",                     "Jauge de
    //  magie",                   "Poder mágico",                             "Barra della magia", "Deutsch"});
    //  itemTable[ENHANCED_MAGIC_METER]              = Item(ITEMTYPE_ITEM,              0x8A,                 true,
    //  &ProgressiveMagic,          ENHANCED_MAGIC_METER,              Text{"Enhanced Magic Meter",            "Jauge de
    //  magie améliorée",         "Poder mágico mejorado",                    "Barra della magia aumentata",
    //  "Deutsch"});
}

Item& ItemTable(const ItemKey itemKey) {
    return itemTable[itemKey];
}

// This function should only be used to place items containing hint text
// at gossip stone locations.
void NewItem(const ItemKey itemKey, const Item item) {
    if (itemKey <= BUY_RED_POTION_50) {
        printf("\x1b[25;0HWARNING: ATTEMPTED TO OVERWRITE ITEM %lu\n", itemKey);
        return;
    }

    itemTable[itemKey] = item;
}
