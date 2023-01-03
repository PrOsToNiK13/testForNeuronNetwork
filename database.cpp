#include "database.h"
#include <QtSql>
#include <QMessageBox>

database::database()
{

}

bool database::connectToDataBase(QString path)
{
       if(!QFile(path).exists()){
           return restoreDataBase(path);
       } else {
           return openDataBase(path);
       }
}

bool database::openDataBase(QString path)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(path);
    if(sdb.open()){
         return true;
    } else {
        return false;
    }
}

bool database::restoreDataBase(QString path)
{
        if(openDataBase(path)){
            return (createTables() ? true : false);
        } else {
            qDebug() << "Не удалось восстановить базу данных";
            return false;
        }
        return false;
}

bool database::createTables()
{
    QSqlQuery query;
    bool isOK = true;
    if(!query.exec( "CREATE TABLE pictures("
                    "pix1 FLOAT, pix2 FLOAT, pix3 FLOAT, pix4 FLOAT, pix5 FLOAT, pix6 FLOAT, pix7 FLOAT, pix8 FLOAT, pix9 FLOAT, pix10 FLOAT, pix11 FLOAT, pix12 FLOAT, pix13 FLOAT, pix14 FLOAT, pix15 FLOAT, pix16 FLOAT,"
                    "pix17 FLOAT, pix18 FLOAT, pix19 FLOAT, pix20 FLOAT, pix21 FLOAT, pix22 FLOAT, pix23 FLOAT, pix24 FLOAT, pix25 FLOAT, pix26 FLOAT, pix27 FLOAT, pix28 FLOAT, pix29 FLOAT, pix30 FLOAT, pix31 FLOAT, pix32 FLOAT, "
                    "pix33 FLOAT, pix34 FLOAT, pix35 FLOAT, pix36 FLOAT, pix37 FLOAT, pix38 FLOAT, pix39 FLOAT, pix40 FLOAT, pix41 FLOAT, pix42 FLOAT, pix43 FLOAT, pix44 FLOAT, pix45 FLOAT, pix46 FLOAT, pix47 FLOAT, pix48 FLOAT, "
                    "pix49 FLOAT, pix50 FLOAT, pix51 FLOAT, pix52 FLOAT, pix53 FLOAT, pix54 FLOAT, pix55 FLOAT, pix56 FLOAT, pix57 FLOAT, pix58 FLOAT, pix59 FLOAT, pix60 FLOAT, pix61 FLOAT, pix62 FLOAT, pix63 FLOAT, pix64 FLOAT, "
                    "pix65 FLOAT, pix66 FLOAT, pix67 FLOAT, pix68 FLOAT, pix69 FLOAT, pix70 FLOAT, pix71 FLOAT, pix72 FLOAT, pix73 FLOAT, pix74 FLOAT, pix75 FLOAT, pix76 FLOAT, pix77 FLOAT, pix78 FLOAT, pix79 FLOAT, pix80 FLOAT, "
                    "pix81 FLOAT, pix82 FLOAT, pix83 FLOAT, pix84 FLOAT, pix85 FLOAT, pix86 FLOAT, pix87 FLOAT, pix88 FLOAT, pix89 FLOAT, pix90 FLOAT, pix91 FLOAT, pix92 FLOAT, pix93 FLOAT, pix94 FLOAT, pix95 FLOAT, pix96 FLOAT, "
                    "pix97 FLOAT, pix98 FLOAT, pix99 FLOAT, pix100 FLOAT, pix101 FLOAT, pix102 FLOAT, pix103 FLOAT, pix104 FLOAT, pix105 FLOAT, pix106 FLOAT, pix107 FLOAT, pix108 FLOAT, pix109 FLOAT, pix110 FLOAT, pix111 FLOAT, pix112 FLOAT, "
                    "pix113 FLOAT, pix114 FLOAT, pix115 FLOAT, pix116 FLOAT, pix117 FLOAT, pix118 FLOAT, pix119 FLOAT, pix120 FLOAT, pix121 FLOAT, pix122 FLOAT, pix123 FLOAT, pix124 FLOAT, pix125 FLOAT, pix126 FLOAT, pix127 FLOAT, pix128 FLOAT, "
                    "pix129 FLOAT, pix130 FLOAT, pix131 FLOAT, pix132 FLOAT, pix133 FLOAT, pix134 FLOAT, pix135 FLOAT, pix136 FLOAT, pix137 FLOAT, pix138 FLOAT, pix139 FLOAT, pix140 FLOAT, pix141 FLOAT, pix142 FLOAT, pix143 FLOAT, pix144 FLOAT, "
                    "pix145 FLOAT, pix146 FLOAT, pix147 FLOAT, pix148 FLOAT, pix149 FLOAT, pix150 FLOAT, pix151 FLOAT, pix152 FLOAT, pix153 FLOAT, pix154 FLOAT, pix155 FLOAT, pix156 FLOAT, pix157 FLOAT, pix158 FLOAT, pix159 FLOAT, pix160 FLOAT, "
                    "pix161 FLOAT, pix162 FLOAT, pix163 FLOAT, pix164 FLOAT, pix165 FLOAT, pix166 FLOAT, pix167 FLOAT, pix168 FLOAT, pix169 FLOAT, pix170 FLOAT, pix171 FLOAT, pix172 FLOAT, pix173 FLOAT, pix174 FLOAT, pix175 FLOAT, pix176 FLOAT, "
                    "pix177 FLOAT, pix178 FLOAT, pix179 FLOAT, pix180 FLOAT, pix181 FLOAT, pix182 FLOAT, pix183 FLOAT, pix184 FLOAT, pix185 FLOAT, pix186 FLOAT, pix187 FLOAT, pix188 FLOAT, pix189 FLOAT, pix190 FLOAT, pix191 FLOAT, pix192 FLOAT, "
                    "pix193 FLOAT, pix194 FLOAT, pix195 FLOAT, pix196 FLOAT, pix197 FLOAT, pix198 FLOAT, pix199 FLOAT, pix200 FLOAT, pix201 FLOAT, pix202 FLOAT, pix203 FLOAT, pix204 FLOAT, pix205 FLOAT, pix206 FLOAT, pix207 FLOAT, pix208 FLOAT, "
                    "pix209 FLOAT, pix210 FLOAT, pix211 FLOAT, pix212 FLOAT, pix213 FLOAT, pix214 FLOAT, pix215 FLOAT, pix216 FLOAT, pix217 FLOAT, pix218 FLOAT, pix219 FLOAT, pix220 FLOAT, pix221 FLOAT, pix222 FLOAT, pix223 FLOAT, pix224 FLOAT, "
                    "pix225 FLOAT, pix226 FLOAT, pix227 FLOAT, pix228 FLOAT, pix229 FLOAT, pix230 FLOAT, pix231 FLOAT, pix232 FLOAT, pix233 FLOAT, pix234 FLOAT, pix235 FLOAT, pix236 FLOAT, pix237 FLOAT, pix238 FLOAT, pix239 FLOAT, pix240 FLOAT, "
                    "pix241 FLOAT, pix242 FLOAT, pix243 FLOAT, pix244 FLOAT, pix245 FLOAT, pix246 FLOAT, pix247 FLOAT, pix248 FLOAT, pix249 FLOAT, pix250 FLOAT, pix251 FLOAT, pix252 FLOAT, pix253 FLOAT, pix254 FLOAT, pix255 FLOAT, pix256 FLOAT, "
                    "pix257 FLOAT, pix258 FLOAT, pix259 FLOAT, pix260 FLOAT, pix261 FLOAT, pix262 FLOAT, pix263 FLOAT, pix264 FLOAT, pix265 FLOAT, pix266 FLOAT, pix267 FLOAT, pix268 FLOAT, pix269 FLOAT, pix270 FLOAT, pix271 FLOAT, pix272 FLOAT, "
                    "pix273 FLOAT, pix274 FLOAT, pix275 FLOAT, pix276 FLOAT, pix277 FLOAT, pix278 FLOAT, pix279 FLOAT, pix280 FLOAT, pix281 FLOAT, pix282 FLOAT, pix283 FLOAT, pix284 FLOAT, pix285 FLOAT, pix286 FLOAT, pix287 FLOAT, pix288 FLOAT, "
                    "pix289 FLOAT, pix290 FLOAT, pix291 FLOAT, pix292 FLOAT, pix293 FLOAT, pix294 FLOAT, pix295 FLOAT, pix296 FLOAT, pix297 FLOAT, pix298 FLOAT, pix299 FLOAT, pix300 FLOAT, pix301 FLOAT, pix302 FLOAT, pix303 FLOAT, pix304 FLOAT, "
                    "pix305 FLOAT, pix306 FLOAT, pix307 FLOAT, pix308 FLOAT, pix309 FLOAT, pix310 FLOAT, pix311 FLOAT, pix312 FLOAT, pix313 FLOAT, pix314 FLOAT, pix315 FLOAT, pix316 FLOAT, pix317 FLOAT, pix318 FLOAT, pix319 FLOAT, pix320 FLOAT, "
                    "pix321 FLOAT, pix322 FLOAT, pix323 FLOAT, pix324 FLOAT, pix325 FLOAT, pix326 FLOAT, pix327 FLOAT, pix328 FLOAT, pix329 FLOAT, pix330 FLOAT, pix331 FLOAT, pix332 FLOAT, pix333 FLOAT, pix334 FLOAT, pix335 FLOAT, pix336 FLOAT, "
                    "pix337 FLOAT, pix338 FLOAT, pix339 FLOAT, pix340 FLOAT, pix341 FLOAT, pix342 FLOAT, pix343 FLOAT, pix344 FLOAT, pix345 FLOAT, pix346 FLOAT, pix347 FLOAT, pix348 FLOAT, pix349 FLOAT, pix350 FLOAT, pix351 FLOAT, pix352 FLOAT, "
                    "pix353 FLOAT, pix354 FLOAT, pix355 FLOAT, pix356 FLOAT, pix357 FLOAT, pix358 FLOAT, pix359 FLOAT, pix360 FLOAT, pix361 FLOAT, pix362 FLOAT, pix363 FLOAT, pix364 FLOAT, pix365 FLOAT, pix366 FLOAT, pix367 FLOAT, pix368 FLOAT, "
                    "pix369 FLOAT, pix370 FLOAT, pix371 FLOAT, pix372 FLOAT, pix373 FLOAT, pix374 FLOAT, pix375 FLOAT, pix376 FLOAT, pix377 FLOAT, pix378 FLOAT, pix379 FLOAT, pix380 FLOAT, pix381 FLOAT, pix382 FLOAT, pix383 FLOAT, pix384 FLOAT, "
                    "pix385 FLOAT, pix386 FLOAT, pix387 FLOAT, pix388 FLOAT, pix389 FLOAT, pix390 FLOAT, pix391 FLOAT, pix392 FLOAT, pix393 FLOAT, pix394 FLOAT, pix395 FLOAT, pix396 FLOAT, pix397 FLOAT, pix398 FLOAT, pix399 FLOAT, pix400 FLOAT, "
                    "pix401 FLOAT, pix402 FLOAT, pix403 FLOAT, pix404 FLOAT, pix405 FLOAT, pix406 FLOAT, pix407 FLOAT, pix408 FLOAT, pix409 FLOAT, pix410 FLOAT, pix411 FLOAT, pix412 FLOAT, pix413 FLOAT, pix414 FLOAT, pix415 FLOAT, pix416 FLOAT, "
                    "pix417 FLOAT, pix418 FLOAT, pix419 FLOAT, pix420 FLOAT, pix421 FLOAT, pix422 FLOAT, pix423 FLOAT, pix424 FLOAT, pix425 FLOAT, pix426 FLOAT, pix427 FLOAT, pix428 FLOAT, pix429 FLOAT, pix430 FLOAT, pix431 FLOAT, pix432 FLOAT, "
                    "pix433 FLOAT, pix434 FLOAT, pix435 FLOAT, pix436 FLOAT, pix437 FLOAT, pix438 FLOAT, pix439 FLOAT, pix440 FLOAT, pix441 FLOAT, pix442 FLOAT, pix443 FLOAT, pix444 FLOAT, pix445 FLOAT, pix446 FLOAT, pix447 FLOAT, pix448 FLOAT, "
                    "pix449 FLOAT, pix450 FLOAT, pix451 FLOAT, pix452 FLOAT, pix453 FLOAT, pix454 FLOAT, pix455 FLOAT, pix456 FLOAT, pix457 FLOAT, pix458 FLOAT, pix459 FLOAT, pix460 FLOAT, pix461 FLOAT, pix462 FLOAT, pix463 FLOAT, pix464 FLOAT, "
                    "pix465 FLOAT, pix466 FLOAT, pix467 FLOAT, pix468 FLOAT, pix469 FLOAT, pix470 FLOAT, pix471 FLOAT, pix472 FLOAT, pix473 FLOAT, pix474 FLOAT, pix475 FLOAT, pix476 FLOAT, pix477 FLOAT, pix478 FLOAT, pix479 FLOAT, pix480 FLOAT, "
                    "pix481 FLOAT, pix482 FLOAT, pix483 FLOAT, pix484 FLOAT, pix485 FLOAT, pix486 FLOAT, pix487 FLOAT, pix488 FLOAT, pix489 FLOAT, pix490 FLOAT, pix491 FLOAT, pix492 FLOAT, pix493 FLOAT, pix494 FLOAT, pix495 FLOAT, pix496 FLOAT, "
                    "pix497 FLOAT, pix498 FLOAT, pix499 FLOAT, pix500 FLOAT, pix501 FLOAT, pix502 FLOAT, pix503 FLOAT, pix504 FLOAT, pix505 FLOAT, pix506 FLOAT, pix507 FLOAT, pix508 FLOAT, pix509 FLOAT, pix510 FLOAT, pix511 FLOAT, pix512 FLOAT, "
                    "pix513 FLOAT, pix514 FLOAT, pix515 FLOAT, pix516 FLOAT, pix517 FLOAT, pix518 FLOAT, pix519 FLOAT, pix520 FLOAT, pix521 FLOAT, pix522 FLOAT, pix523 FLOAT, pix524 FLOAT, pix525 FLOAT, pix526 FLOAT, pix527 FLOAT, pix528 FLOAT, "
                    "pix529 FLOAT, pix530 FLOAT, pix531 FLOAT, pix532 FLOAT, pix533 FLOAT, pix534 FLOAT, pix535 FLOAT, pix536 FLOAT, pix537 FLOAT, pix538 FLOAT, pix539 FLOAT, pix540 FLOAT, pix541 FLOAT, pix542 FLOAT, pix543 FLOAT, pix544 FLOAT, "
                    "pix545 FLOAT, pix546 FLOAT, pix547 FLOAT, pix548 FLOAT, pix549 FLOAT, pix550 FLOAT, pix551 FLOAT, pix552 FLOAT, pix553 FLOAT, pix554 FLOAT, pix555 FLOAT, pix556 FLOAT, pix557 FLOAT, pix558 FLOAT, pix559 FLOAT, pix560 FLOAT, "
                    "pix561 FLOAT, pix562 FLOAT, pix563 FLOAT, pix564 FLOAT, pix565 FLOAT, pix566 FLOAT, pix567 FLOAT, pix568 FLOAT, pix569 FLOAT, pix570 FLOAT, pix571 FLOAT, pix572 FLOAT, pix573 FLOAT, pix574 FLOAT, pix575 FLOAT, pix576 FLOAT, "
                    "number0 FLOAT, number1 FLOAT, number2 FLOAT, number3 FLOAT, number4 FLOAT, number5 FLOAT, number6 FLOAT, number7 FLOAT, number8 FLOAT, number9 FLOAT);")){
        isOK = false;
        qDebug() << "table pictures created";
    }
    if (isOK){
        qDebug() << "Таблицы созданы!";
        return true;
    } else {
        qDebug() << "DataBase: error of create";
        return false;
    }
    return false;
}
